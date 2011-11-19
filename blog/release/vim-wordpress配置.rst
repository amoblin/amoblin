vim wordpress配置
==================
.. id: 80
.. tags:

vim下发布博客，我用过两种：vimrepress，blogpost。

vimrepress作为vim插件使用，需要在vim里发布。这一点我不喜欢。我只用vim编辑，完工后希望命令行发布。

blogpost就是这样一个命令行工具。

原作者是用asciidoc来写文档，然后用blogpost发布。

但我使用ReST，这里就用不到blogpost自带的asciidoc接口了。但经过修改，基本可用。

我使用vim + blogpost 发布博客的过程如下：

1. 编写ReST文档
2. 生成HTML文档

.. sourcecode:: console

    $ rst2html.py --link-style --stylesheet=highlight.css blog.rst blog.html

这里使用外部CSS文件，从而使生成的HTML文档更美观。

3. 提取正文
   使用blogpost发布时，需要提取正文。

.. sourcecode:: console

	$ sed -n '/<div /,/<\/body>/p' blog.html | sed -e '1,3d' -e '$d' -e '$d' > post.html

这个脚本是乖乖上午查阅资料写出来的。

4. 通过blogpost发布

.. sourcecode:: console

    $ blogpost.py -d html -t "vim wordpress配置" post post.html
    blogpost.py: updating published post 'vim wordpress配置'...
    blogpost.py: id: 80
    blogpost.py: url: http://amoblin.sinaapp.com/?p=80

上述信息告诉了本篇文章的id号，以后可以通过id号更新博客：

.. sourcecode:: console

    $ wpc.py -d html --post-id 80 update post.html
    blogpost.py: updating published post 'vim wordpress配置'...
    blogpost.py: id: 80
    blogpost.py: url: http://amoblin.sinaapp.com/?p=80

