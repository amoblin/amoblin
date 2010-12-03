==================
|ArticleTitle|
==================

------------
for Docbones
------------

:作者: |AuthorOSSXP|_
:网址: http://www.ossxp.com/
:版本: |doc_rev|
:日期: |doc_date|
:版权信息: |Creative Commons|_

.. |date| date::        %Y-%m-%d %H:%M
.. |doc_rev| replace::  @UnkownENV(DOC_REV)@
.. |doc_date| replace:: 2010-12-01 15:19:39
.. |Creative Commons|   image:: images/cc-icon.png
.. _Creative Commons:   http://creativecommons.org/licenses/by-sa/3.0/
.. |AuthorOSSXP|        replace:: 北京群英汇信息技术有限公司
.. _AuthorOSSXP:        http://www.ossxp.com/
.. |ArticleTitle|       replace:: 群英汇博客 
.. _ArticleTitle:       http://www.ossxp.com/doc/

.. contents:: 目录
.. sectnum::

.. include:: DEFINES.txt
   :start-after: START_HTML_HEADER_FOOTER
   :end-before: END_HTML_HEADER_FOOTER

.. raw:: pdf

   Transition Dissolve 1
   PageBreak contentsPage

绑定变量
========

当python脚本被调用的时候，会创建一组变量，这些变量用于在脚本里面访问其他的Zope对象和脚本，要查看和定义这些变量，可以到Binding标签视图里。其他Zope对象，像Perl脚本，DTML文档对象等，这些变量都无效。但ZPT里有相似的变量组。

一般情况下，这些变量的设置都不需要更改。下面介绍这些变量分别如何工作，以及如何在脚本中使用。

Context 默认绑定到context，指向调用本脚本的对象

Container 默认绑定到container，脚本定义处

Script 默认绑定到script，指向脚本自身

Namespace 默认留空。

如果使用ftp上传文件，那么就要在唉脚本的开头通过注释将上述内容列出，如下例：

::

## Script (Python) "example"
##bind container=container
##bind context=context
##bind namespace=
##bind script=script
##bind subpath=traverse_subpath
##parameters=name, age
##title=


其中的parameters列是脚本的参数。注意这些注释不仅仅是注释，它们包含语义信息。所以不能随便写，比如在bind前不能有空格，在parameters前也不能有空格等等。

如何使用呢？通过这些绑定，我们可以访问我们想要的对象。比如，通过context可以访问调用此脚本的对象。回到Zoo例子，下面这行：

::

 animail_id = context.getId()

就可以得到id值"hippo"，因为hoppo是这里的context，它的id是"hoppo"。我们可以通过这个方法访问任何对象的id，因为这个方法几乎存在于任何一个对象里。


------------

在通过表单获取输入值时，我们会得到一个REQUEST对象，它代表一个Zope web请求，存在于context里。例如/zoo/hippo/feed?food_type=spam，我么可以通过context.REQUEST.food_type来访问foot_type的值。另外一种使用REQUEST的方法是作为脚本的参数。 如果REQUEST是脚本的一个参数的话，Zope会忽略HTTP请求，直接把请求分配给这个参数。这时可以通过REQUEST.food_type来获取值。


分段以及断行
------------

这是一个段落的开始，
本行自动续行。下面用一个空行分隔两个段落。

新的段落。

缩进也是语法(类python)
-----------------------

这是一个段落。下面段落用空格缩进。

  缩进的段落
  等量缩进， *续行* 。

    继续缩进的 *段落* 。

结束缩进，成为一个段落。

#. 列表1
#. 列表2

..

  为了显示为缩进,而非作为列表的内容解析，前面的段落用空注释结束列表

#. 列表2

预格式化文本(literal blocks)
------------------------------

这是一个段落。下面的双冒号的孤立段落，将会开启一个样式为 literal-block 的 PRE 块。
在该块中，reST 语法不做解析。

::

  双冒号的孤立行，开始 pre formatted text
                  __更上一层楼
                _|
              _|
  欲穷千里目-|

  缩进中，reST **不** 进行解析

缩进停止，则开始新的段落。

----

段落结尾的两个冒号，下个段落也开始一个literal block: ::

 缩进样式 *不解析*
   缩进样式 *不解析*
 缩进样式 *不解析*

引用块
--------

双冒号的孤立段落，也可以开启一个引用式的缩进，就像邮件引用一样。
在该块中，reST 语法不做解析。

::

> *something*
> xyz
>> xyz
> xyz

行块
-----

下面的段落中，以竖线 | 和一个空格做起始，维持换行的格式

| 开始一个line block
| 另外的一行,
  续行。
| 再一行
|    含有缩进的一行
|  含有缩进的一行
|    含有缩进的一行

另外一个段落。

文字样式
--------

- *斜体*
- **粗体**
- 粗斜体如何显示？？？
- 解析文本调用缺省解析器: `子曰：“学而时习之不亦乐乎？”`
- 以 tt 标签显示的: ``import os``
- 水的分子式是 |H2O|.
- 相对论公式： |e=mc2|.

.. |H2O| replace:: H\ :sub:`2`\ O
.. |e=mc2| replace:: E = mc\ :sup:`2`

列表
-----

* 子弹头列表

   - 子列表
   - 子列表

* 子弹头列表2

   #. 自动编号列表1
   #. 自动编号列表2

   #. 自动编号列表3

* 子弹头列表3

   2. 从2开始编号
   3. 编号顺序递增

       a) Item 3a.
       b) Item 3b.

   4. 列表4

       i) Item 4i.
       ii) Item 4ii.

定义
-----

apple
  一种水果

  知名软件公司

term2 : 名词
  定义

分隔线
------

四个减号开始一个分隔线

------

分隔线下内容。。。


高级格式说明
============

超链接
------

直接嵌入超链接
~~~~~~~~~~~~~~

群英汇的网址是: http://www.ossxp.com.

直接嵌入具名超链接
~~~~~~~~~~~~~~~~~~~

这个链接会自动创建一个具名链接，除了这里显示链接外，
还可以在后面引用。如: `北京群英汇 <http://www.ossxp.com>`_
是开源软件服务提供商。

这里引用 北京群英汇_

定义和引用具名超链接
~~~~~~~~~~~~~~~~~~~~

定义超链接格式： ``.. _hyperlink-name: link-block``

内部anchor
^^^^^^^^^^
定位到 target_

在文内通过一个不包含 link-block 的具名链接定义，即定义此 anchor，用于文内跳转。

.. _target:

上面是一个名为 target 的文内anchor。

指向URI的超链接
^^^^^^^^^^^^^^^

群英汇_ [#]_ 的主页: ossxp_, 发邮件给 `Jiang Xin`_


.. _群英汇: ossxp_
.. _ossxp: http://www.ossxp.com/
.. _Jiang Xin: worldhello.net@gmail.com
.. [#] 链接的定义可以指向另外一个链接的定义

匿名超链接
~~~~~~~~~~

格式：
  * 引用时，后面是两个下划线，而不是一个
  * 定义时，以两个下划线为名称，不包含链接名字

示例： See `the web site of my favorite programming language`__.

.. __: http://www.python.org

一个文档可以包含多个匿名超链接，要求：

 * 引用的数量和定义的数量相同
 * 定义和引用一一对应


脚注
----

脚注就是以顺序的数字显示链接，并指向脚注区域的相关注释。

手动编号的脚注
~~~~~~~~~~~~~~

方括号 [1]_ 内手动编号 [1]_ ，别忘了结尾的下划线 [3]_, 可以重复引用脚注 [3]_

.. [1] 嵌入的脚注前后要有空格
.. [2] 阿拉伯数字
.. [3] 下划线只在引用时需要提供，定义时，不需要

自动编号的脚注
~~~~~~~~~~~~~~

自动编号的脚注是用井号 [#]_ 作为 label 的脚注 [#]_

.. [#] 以 # 代替数字
.. [#] 自动增加编号。定义的时候也写成 #，而不要用数字

但是自动编号的局限性是：不能对一个脚注在多处引用。

对于需要在多处引用自动编号的脚注，可以使用下面的带有 label 的自动编号脚注。


带 label 自动编号的脚注
~~~~~~~~~~~~~~~~~~~~~~~

带有label 的自动脚注 [#note]_ 会根据前面的脚注情况，自动编号。显示为
"[n]".  如果多此引用此脚注，可以多次出现同 label 的自动脚注 [#note]_ 。
如果向使用链接指向脚注，可以用 *简单链接* 语法做指向。如： note_

.. [#note] This is the footnote labeled "note".

自动符号脚注
~~~~~~~~~~~~~~~~~~~~~~~

可以用星号 * 作为脚注的label，会依次用不同的符号来显示。脚注 [*]_,脚注 [*]_,脚注 [*]_,脚注 [*]_,脚注 [*]_ ...

.. [*] 以符号的形式显示的脚注
.. [*] 以符号的形式显示的脚注
.. [*] 以符号的形式显示的脚注
.. [*] 以符号的形式显示的脚注
.. [*] 以符号的形式显示的脚注

引证
----

引证就是以有意义的单词或者规定的格式编码显示链接，并指向引证区域的相关注释。

和脚注类似，不过是直接使用字母而非数字作为 label。 [CIT2002]_.

.. [CIT2002] This is the citation.  It's just like a footnote,
   except the label is textual.

替换
----

用竖线中间夹着要替换的单词。定义替换采用两个点的类似注释的语法。

文字替换
~~~~~~~~

|RST|_ is a little annoying to type over and over, especially
when writing about |RST| itself, and spelling out the
bicapitalized word |RST| every time isn't really necessary for
|RST| source readability.

.. |RST| replace:: reStructuredText
.. _RST: http://docutils.sourceforge.net/rst.html

图片替换
~~~~~~~~

* 嵌入 |CC| 授权协议图标。
* 带有链接的 |CC with link|_ 授权协议图标。

.. |CC| image:: images/cc-icon.png
.. |CC with link| image:: images/cc-icon.png
.. _CC with link: http://creativecommons.org/licenses/by-sa/3.0/


表格
----

* 英文表格

  +------------+------------+-----------+
  | Header 1   | Header 2   | Header 3  |
  +============+============+===========+
  | body row 1 | column 2   | column 3  |
  +------------+------------+-----------+
  | body row 2 |    `ps -ef | grep py`  |
  |            |                        |
  +------------+------------+-----------+
  | body row 3 | Cells may  | - Cells   |
  +------------+ span rows. | - contain |
  | body row 4 |            | - blocks. |
  +------------+------------+-----------+

* 中文表格

  +------------+------------+-----------+
  |    表头1   |    表头2   |    表头3  |
  +============+============+===========+
  | 表格行1    |    列 2    |    列 3   |
  +------------+------------+-----------+
  | 表格行2    |    `ps -ef | grep py`  |
  |            |                        |
  +------------+------------+-----------+
  | 表格行3    | 单元格     | - 单元格  |
  +------------+ 跨越多行。 | - 包含    |
  | 表格行4    |            | - 块.     |
  +------------+------------+-----------+

* 简单表格


Simple table:

=====  =====  ======
   Inputs     Output
------------  ------
  A      B    A or B
=====  =====  ======
False  False  False
True   False  True
False  True   True
True   True   True
=====  =====  ======

指令扩展
============

图片
----

 * 嵌入图片

   .. image:: images/cc-icon.png

 * 带标题的图片

   .. figure:: images/cc-icon.png

      Creative Commons 授权图标（by-sa）

 * 图片缩放

   .. figure:: images/cc-icon.png
      :scale: 50

      缩放了 50% 的图片

 * 图片缩放

   .. figure:: images/cc-icon.png
      :height: 11
      :width: 11

      设置了固定高和宽度的图片

警告
----

.. note:: This is a paragraph

   - Here is a bullet list.

.. Danger:: modify at your own risk!


