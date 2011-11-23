==================
linux shell 重定向
==================
.. id: 105

shell下有标准输入stdin，标准输出stdout，标准错误输出stderr，标示符分别为0，1，2。
默认的标准输入是键盘，标准输出和标准错误输出是显示器。

利用重定向可以改变默认的标准输入输出，使用"<"来重定向标准输入，利用">"来进行重定向输出。

另外，可以使用">>"在重定向输出时不是覆盖，而是追加。

重定向标准输入我不太常用，仅对输出重定向举例如下：

1. 将echo的标准输出重定向到/tmp/a.txt文件

.. sourcecode:: console

    $ echo hello world
    hello world
    $ echo hello world > /tmp/a.txt
    $ cat /tmp/a.txt
    hello world

2. 将echo的标准输出重定向追加到/tmp/a.txt文件

.. sourcecode:: console

    $ echo hello world >> /tmp/a.txt
    $ cat /tmp/a.txt
    hello world
    hello world


3. 将标准错误输出重定向到/tmp/error.log文件

.. sourcecode:: console

    $ cat not-exists.txt
    cat: not-exists.txt: 没有那个文件或目录
    $ cat not-exists.txt 2> /tmp/error.log
    $ cat /tmp/error.log
    cat: not-exists.txt: 没有那个文件或目录

4. 将标准输出和标准错误输出都重定向到/tmp/log文件

.. sourcecode:: console

    $ cat /tmp/a.txt not-exist
    hello world
    hello world
    cat: not-exitst: 没有那个文件或目录
    $ cat /tmp/a.txt not-exist > /tmp/log 2>&1
    $ cat /tmp/log
    hello world
    hello world
    cat: not-exitst: 没有那个文件或目录

