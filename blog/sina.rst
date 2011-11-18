2011年11月18日 星期五 11时49分14秒
==================================

DONE
-----
寻找源码查阅工具。初步锁定cflow

参考 http://www.hzmangel.info/blog/archives/260 完成docutils的pygments配置：
在directives目录下编辑__init__.py文件，加入注册：
 'sourcecode': ('rst_directive', 'Pygments'),

TODO
-----

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
