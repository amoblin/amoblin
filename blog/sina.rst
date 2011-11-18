2011年11月18日 星期五 11时49分14秒
==================================

  今天主要解决了Monitor监听服务重复初始化的错误。

DONE
-----
1. 寻找源码分析工具和函数调用关系图工具。初步锁定cflow。 使用cflow查找函数调用脉络。

2. 解决Monitor重复初始化监听服务的错误。

分析monitor_init函数，下面是系统日志中出现绑定错误的地方(位于monitor_init函数中)：

.. sourcecode:: c

    417  if (listenfd < 0) {
    418      WLOG_INFO("[monitor] bind to port %ju failed. ", (uintmax_t)port);
    419      printf("Monitor bind to port %ju failed.\n", (uintmax_t)port);
    420      return NULL;
    421  } else {
    422      mnt_fd = listenfd;
    423      WLOG_INFO("[monitor] Monitor OK. Now listen on port %ju.", (uintmax_t)port);
    424  }

根据调用关系，找到了libmod.c文件，其中123行调用了上述函数：

.. sourcecode:: c

    114  int
    115 _mod_init(char * mod_name, MOD_PARA * mpp)
    116 {
    117     /* check whether the mod version match the csf core version * /
    118     if (CORE_VER_REQUIRE > mpp->vcbp->lowest_ver)
    119         return MOD_VER_ERR;
    120 
    121     logger_init(mpp->chp->logp, NULL, 0, 0);
    122     stage_init(mpp->chp->stagep);
    123     monitor_init(mpp->chp->mntp);
    124 
    125     pthread_once(&init_done, pthr_key_create);
    126     pthread_setspecific(pthread_key, NULL);
    127 
    128     ripp = &(mpp->mcp->request_init);
    129     rdpp = &(mpp->mcp->request_deinit);
    130     rhpp = &(mpp->mcp->request_handler);
    131 
    132     return mod_init(mod_name);
    133 }

显然，在初始化模块时一起初始化了monitor，而http中有http_io和http_upload两个模块，所以在初始化http_upload时出现了绑定失败。

我试图将monitor的初始化转移到模块初始化之前。但一直没有找到合适的地方。最后，我采取了一个简单方法，注释掉。

运行通过，而且根据输出，发现其后单独进行了monitor的初始化。所以这里确实可以注释掉。

3. 解决了运行错误：

.. sourcecode:: console

    $ ./csfd-worker
    ...
    ./csfd-worker: symbol lookup error: .//http_upload.so: undefined symbol: CSF_UNUSED_ARG

原来在http_upload.c中忘了添加utils.h头文件，而CSF_UNUSED_ARG在此文件中定义。


4. 解决了上述错误以后运行如下：

.. sourcecode:: console

    $ sudo ./csfd-workder
    CSF[21403] starting...
    parse_conf_file: can not get [server]->request_timeout, default used.
    parse_conf_file: can not get [server]->log_ident, default used.
    parse_conf_file: can not get [server]->bind_ip, default used.
    parse_conf_file: can not get [server]->mod_dir, default used.
    parse_conf_file: can not get [server]->monitor_bind_ip, default used.
    maximum file descriptors: 10240
    PANTAO 1.0-alpha1 Build-Date: Nov 18 2011 10:14:20
    load_protocol_mod[66]: "PROTOCOL MODULE: http.so"
    parse_conf_file: can not get [http_io.so]->stage_id, default used.
    parse_conf_file: can not get [http_io.so]->delay, default used.
    parse_conf_file: can not get [http_upload.so]->stage_id, default used.
    parse_conf_file: can not get [http_upload.so]->delay, default used.
    parse_conf_file: can not get [server]->monitor_bind_ip, default used.
    my pid is 3078440640.
    [monitor] Monitor OK. Now listen on port 22222.
    thread 2970839920 listen.
    main[532]: "Fatal Error, SERVER DOWN!"

查看日志：

.. sourcecode:: console

    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: pipeline_init[846]: "Starting to initialize thread pool..."
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: thread_pool_init[736]: "Start to initiate thread group includes 200 threads"
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: thread_pool_init[736]: "Start to initiate thread group includes 200 threads"
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: pipeline_init[963]: "All thread(s) is initialized!"
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: monitor_init[423]: "[monitor] Monitor OK. Now listen on port 22222."
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: tcp_socket_init[560]: "listening socket 5 is created"
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: tcp_socket_init[589]: "start listening from socket 5"
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: set_user_group[78]: "can't find username: www"
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: server_init[267]: "Can't set user or group!"
    Fri Nov 18 11:18:25 2011 shiroh-laptop csf_log[21403]: main[530]: "Fatal Error, SERVER DOWN!"

发现是本系统无www用户和组。

TODO
-----

创建www用户和组，进一步研究。


参考 http://www.hzmangel.info/blog/archives/260 完成docutils的pygments配置：
在directives目录下编辑__init__.py文件，加入注册：
'sourcecode': ('rst_directive', 'Pygments'),


2011年11月17日 星期四 10时43分54秒
==================================

TODO
-----

DONE
----

运行错误：
./csfd-worker: symbol lookup error: .//http_upload.so: undefined symbol: CSF_UNUSED_ARG

查看日志为：
Thu Nov 17 10:48:31 2011 shiroh-laptop csf_log[32474]: monitor_init[423]: "[monitor] Monitor OK. Now listen on port 22222."
Thu Nov 17 10:48:31 2011 shiroh-laptop csf_log[32474]: unix_listen[708]: "[monitor] error occured when bind to port 22222."
Thu Nov 17 10:48:31 2011 shiroh-laptop csf_log[32474]: monitor_init[418]: "[monitor] bind to port 22222 failed. "

锁定monitor.c文件。需要了解多线程编程知识。

网络编程学习：实现获取服务器当前时间。


2011年11月16日 星期三 17时24分24秒
==================================

TODO
----
waitpid学习

DONE
-----
