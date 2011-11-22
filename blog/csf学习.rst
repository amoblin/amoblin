==================
CSF学习
==================

.. contents:: 目录

.. |rst| replace:: :emphasis:`re`\ :strong:`Structured`\ :sup:`Text`
.. |time| date:: %y%m%d  %H:%M

CSF是通用服务框架(Common Server Frame)，通过动态加载各种服务，如HTTP，FTP，SMTP等，来实现HTTP服务器，FTP服务器，SMTP服务器。

csfd为主守护进程，由它创建csfd-worker进程。每当csfd-worker进程以外退出后，都会被csfd重新创建，实现自动重启。

核心在csfd-worker程序。

相关数据结构解析
----------------

读取配置文件到如下结构体：

.. sourcecode:: c
    
        26 typedef struct csf_conf {
        27     COMM_PROTO_OPS * cp_ops;
        28     int server_port;
        29     int server_timeout;
        30     int pipeline_queue_size;
        31     int daemonize;
        32     int request_timeout;
        33     int monitor_enable;
        34     int monitor_port;
        35     char    server_protocol[CONF_ITEM_LEN + 1];
        36     char    protocol_module[CONF_ITEM_LEN + 1];
        37     char    user[CONF_ITEM_LEN + 1];
        38     char    group[CONF_ITEM_LEN + 1];
        39     char    log_ident[CONF_ITEM_LEN + 1];
        40     char    bind_ip[CONF_ITEM_LEN + 1];
        41     char    mod_dir[CONF_ITEM_LEN + 1];
        42     char    monitor_bind_ip[CONF_ITEM_LEN + 1];
        43 } CSF_CONF;

在全局变量main_conf保存。

其中第一个数据成员cp_ops是指向TCP或UDP结构体的指针，它指向的结构体定义为：

.. sourcecode:: c

       36 struct comm_proto_ops {
       37     const char * proto_name;
       38     int sockfd;
       39     PROTO_INIT * proto_init;
       40     CONN_HANDLER * conn_handler;
       41     SOCKET_EVENT_HANDLER* event_handler;
       42     SEND_BACK* send_back;
       43     SOCKET_SENDFILE* send_file;
       44     WRITEV_BACK* writev_back;
       45     CONN_CLOSE* conn_close;
       46     PORT_CLOSE* port_close;
       47     WRITE_BACK* write_back;
       48 };


全局变量csf_comm_proto，是含有2个上述结构体元素的数组，元素分别为TCP，UDP的定义实现。保存tcp和udp类型的服务。根据服务的类型，cp_ops指向对应的数组元素。

tcp类型的结构定义：

.. sourcecode:: c

    46 COMM_PROTO_OPS tcp_ops = {
    47     .proto_name = "tcp",
    48     .sockfd = -1,
    49     .proto_init = tcp_socket_init,
    50     .conn_handler = tcp_conn_handler,
    51     .event_handler = tcp_socket_event_handler,
    52     .send_back = tcp_send_back,
    53     .conn_close = tcp_conn_close,
    54     .port_close = tcp_port_close,
    55     .send_file = tcp_sendfile,
    56     .writev_back = tcp_writev,
    57     .write_back = tcp_write
    58 };

初始化模块
-----------

csfd-worker根据配置文件进行模块参数的初始化，由函数csf_init负责。

具体分为：初始化默认值，读取配置文件初始化。

初始化默认值 csf_conf_init
```````````````````````````

  1. 将main_conf的各项初始化为默认值。

读取配置文件初始化 config_init
```````````````````````````````

  1. 根据配置文件中[server]段初始化相应数据成员。

  #. 根据服务的类型（tcp or udp）挂上对应类型的结构体。

初始化内存池 mp_init
`````````````````````

初始化模块配置: mod_config_init @ module.c
````````````````````````````````````````````

  1. 根据mod_dir动态加载模块。比如http.so，同时将动态库函数_protocol_init和静态全局变量_protocol_init对应起来。

  #. 加载其后各段。比如http_io.si, http_upload.so，同时_mod_init函数。

初始化管道 pipeline_init @ pipeline.c
``````````````````````````````````````

初始化协议模块 app_proto_init @ protocol.c
```````````````````````````````````````````

定义ppp是如下的结构体变量：

.. sourcecode:: c
    
    38 typedef struct protocol_parameter{  
    39     VCB* vcbp;  
    40     PROTO_CONFIG* pcp;  
    41     COMM_HANDLE* chp;
    42 } PROTO_PARA;

pcp: 协议配置指针 protocol config pointer. 指向全局变量pc：

.. sourcecode:: c

    20 PROTO_CONFIG pc = {
    21     .protocol_session_start = NULL,
    22     .protocol_session_entry = NULL,
    23     .protocol_session_end = NULL,
    24     .local_entry = NULL,
    25 };

PROTO_CONFIG结构体定义如下：

.. sourcecode:: c
  
    31 typedef struct protocol_configs {
    32     PROTOCOL_SESSION_START* protocol_session_start;
    33     PROTOCOL_SESSION_ENTRY* protocol_session_entry;
    34     PROTOCOL_SESSION_END* protocol_session_end;
    35     LOCAL_ENTRY* local_entry;
    36 } PROTO_CONFIG;


接下来使用动态链接库函数指针执行初始化函数：

.. sourcecode:: c
    
    90         rv = _protocol_init(prot_name, &ppp);

具体执行的函数在libprotocol.c中：

    初始化日志
    初始化内存池
    初始化监控器
    初始化提交请求

    设置全局变量g_pcp指针指向全局变量pcp

    执行服务的protocol_init函数进行服务初始化

http服务初始化 protocol_init @ http.c
--------------------------------------

protocol_init 函数主要设置libprotocol中的全局变量g_pcp结构体：

.. sourcecode:: c

    433     set_protocol_session_start(http_session_start);
    434     set_protocol_session_entry(http_session_entry);
    435     set_protocol_session_end(http_session_end);

最终将http会话处理设置到全局变量pc中去。

初始化协议服务
--------------

初始化完毕后，开始启动服务。

由server.c文件中server_init函数完成。根据初始化的内容，设置对应的协议服务。

初始化Socket
`````````````

使用proto_init指向的函数初始化Socket。比如HTTP的话是TCP套接字。

.. sourcecode:: c

    252         fd = ops->proto_init(conf->server_port, 
    253             conf->bind_ip, conf->server_timeout);
    254 

设置用户和组
`````````````

(在配置文件中指定)

事件句柄初始化
```````````````

初始化管道，阻塞和非阻塞的。

http事件处理
`````````````

具体到HTTP事件处理，也就是http_session_entry函数。

前面都正常，后面提交到管道，出错了。

.. sourcecode:: c

    349     /* submit to pipeline \*/
    350     if (req_info->is_to_submit == 1)
    351     {
    352         req_info->is_to_submit = 0;
    353 
    354         r = submit_request(0, rqstpp, req_info, http_data_cleaner, http_request_responder, 0);
    355         if (r < 0)
    356         {
    357             WLOG_ERR("pipeline error. %ld", r);
    358             return PROTOCOL_DISCONNECT;
    359         }

发现是r为-1， 从submit_request中查看r值：

.. sourcecode:: c

    185     if (pipeline_id >= PIPELINE_SIZE) {
    186         WLOG_ERR("pipeline_id %d 超过PIPELINE_SIZE %d !", pipeline_id, PIPELINE_SIZE);
    187         return (SUBMIT_GENERIC_ERROR);
    188     }

添加了一条显示错误日志的信息，运行显示如下：

.. sourcecode:: console

    submit_request[186]: "pipeline_id -1283393984 超过PIPELINE_SIZE 16 !"

pipeline并不是期望的小整数。一路回溯传入值，最终定位到protocol.c中如下函数

.. sourcecode:: c

     44 int
     45 do_protocol_session_entry(void* csp,
     46     CONN_INFO* cip, void* prot_data, void* data, int len)
     47 {
     48     if (pc.protocol_session_entry != NULL) {
     49         printf("%d\n", csp);
     50         return (pc.protocol_session_entry(csp, cip, prot_data, data, len));
     51     } else {
     52         WLOG_ERR("protocol_session_entry() is NULL!");
     53         return (CSF_OK);
     54     }
     55 }

其中csp是pipeline_id的原始值。

