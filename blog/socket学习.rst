socket学习
===========

socket类型： 流式SOCKET_STREAM，数据报式SOCKET_DGRAM。前者面向连接，后者无连接。

socket函数：
    int socket(int domain, int type, int protocol);

domain通常为PF_INET ，表示互联网协议族（TCP/IP协议族）。
