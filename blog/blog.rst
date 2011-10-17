Linux笔记
=========
查找：
find：
在硬盘搜索

.. sourcecode:: shell

    $ find . -name * .c

在当前目录下查找后缀为c的文件

locate: 
比find快，在数据库搜索

.. sourcecode:: shell

    $ locate ~/*.pdf
    
在用户主目录下查找后缀为pdf的文件

