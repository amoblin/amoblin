MongoDB学习
===========

Ubuntu安装
------------

.. sourcecode:: shell

    $ sudo apt-get install mongodb

插入数据
---------

.. sourcecode:: shell

    > post = { "title": "test", "content": "hello, world!", "date": new Date() }
    > db.blog.insert(post)

查找数据
----------

.. sourcecode:: shell

    > db.blog.find()
    > db.blog.findOne()

使用find时，默认最多显示20条记录，findOne显示一条。

更新数据
---------

.. sourcecode:: shell

    > 

