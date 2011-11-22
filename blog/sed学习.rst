sed学习
=======

使用shell变量
-------------

用单引号实现：

.. sourcecode:: console

    $ sed -n 's/hello,.*/hello,'$1'/' test.txt    

