使用vim发布wordpress博客
========================
.. id: 80
.. tags:

总体流程：
1. 使用vim编写ReST文档
2. 使用rst2html.py将ReST文档转换为HTML文档
3. 使用wordpress的XML-RPC接口发布博客

ReST语法
---------

要做到第一步，需要学习ReST语法。这个很简单，我常用到的就2个，并且1个还不算ReST的～

最常用的语法是：标题。

标题下面用同一个符号重复排序，不要短于标题内容。

标题之间的层次关系通过符号体现，如果是新符号，那么递进一层，否则和之前符号层次相同。如下：

.. sourcecode:: rest

    使用vim发布wordpress博客
    ========================
        
    ReST语法
    ---------

这样第一行就是一级标题，第四行就是二级标题。

语法1.5：换行 空行即换行。

语法2：代码
先看一个代码：

.. sourcecode:: c

    #include <stdio.h>

    int main() {
        printf("Hello, world!\n");
        return 0;
    }

实现上述效果的ReST代码为：

.. sourcecode:: text

    .. sourcecode:: c

        #include <stdio.h>

        int main() {
            printf("Hello, world!\n");
            return 0;
        }


我常用的就这2个。其他像列表呀什么的，需要再研究。反正一篇码文并茂的博客，学会这两点就OK了～

生成HTML
---------

由ReST文档生成HTML的命令是rst2html.py，这个由Docutils软件包提供。

Ubuntu/Debian下安装如下：

.. sourcecode:: console

    $ sudo apt-get install python-docutils

安装了python的任何系统下，可以通过easy_install安装，但前提是安装了setuptools：

.. sourcecode:: console

    $ sudo easy_install docutils

现在就可以通过rst2html.py来生成html文档啦：

.. sourcecode:: console

    $ rst2html.py blog.rst blog.html

但如果文档里有sourcecode语法的话，会报错。这是因为sourcecode不是ReST提供的，而是由另一个叫做Pygmentize的软件包提供的：

Docutils语法高亮配置
---------------------

Pygmentize是一个语法高亮的软件，能够将程序源代码生成彩色的HTML文件。

.. sourcecode:: console

    $ sudo apt-get install python-pygmentize
    $ sudo easy_install pygmentize

请对号入座，执行安装。具体用法请--help。

这里说说在Docutils中的配置。

Docutils中的ReST不支持语法高亮，但提供了directive扩展，通过注册来自定义处理过程。自定义的关键字格式如下： 

.. sourcecode:: text

    .. keyword::

刚才我们看到了，pygmentize在directive中注册的关键字是sourcecode。

首先下载rst的directive处理文件：

然后复制到directives目录：

.. sourcecode:: console

    $ sudo cp rst-directive.py `python -c "import docutils; print docutils.__path__[0]"/parsers/rst/directives

修改directives目录下__init__.py文件，从而注册sourcecode关键字：

.. sourcecode:: python

    _directive_registry = {
          'sourcecode': ('rst_directive', 'Pygments'),
          'attention': ('admonitions', 'Attention'),
    
注意这里的第二行是我们添加的注册行。

到此为止，可以顺利生成彩色代码了。

使用命令行发布博客
------------------

当确定了HTML内容可以发布以后，就要提交到wordpress了。这时最希望的就是立刻提交，其他一切都是多余。

基于此，我在尝试了vimrepress一次以后，立刻放弃了。

现在我要给大家隆重介绍的是blogpost.py！




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

