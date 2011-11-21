CSF学习
=======

csfd为主守护进程，由它创建csfd-worker进程。每当csfd-worker进程以外退出后，都会被csfd重新创建，实现自动重启。

核心在csfd-worker程序。

配置文件
--------

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

其中第一项的结构体定义为：

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


在全局变量main_conf保存。

初始化模块
-----------

csfd-worker根据配置文件进行模块参数的初始化，由函数csf_init负责。

此外，还有函数指针的初始化。

初始化协议服务
--------------

由server.c文件中server_init函数完成。根据初始化的内容，设置对应的协议服务。

设置事件响应。


加载协议，模块。

初始化协议
-----------

初始化模块
-----------
