sed学习
=======

使用shell变量
-------------

用单引号实现：

.. sourcecode:: bash

    #/bin/sh
    sed -n 's/hello,.*/hello,'$1'/' test.txt    

打印
-----

.. sourcecode:: console

    $ sed -n '2p' test.txt

删除
----

.. sourcecode:: console

    $ sed -e '$d' test.txt
