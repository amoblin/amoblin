=============================
wordpress blog id不连续的解决
=============================

wp两个特性：自动保存(auto save) 和 版本记录(revisions)。

禁用自动保存
============

修改wp-config.php,增加一行：

.. sourcecode:: php

    define( 'AUTOSAVE_INTERVAL', 300 );

上述单位是秒。 这里每5分钟自动保存一次。

禁用版本记录
============

Revisions的设置选项说明如下：

There are options, but they are hidden well :) There is a constant (not even filterable) that can be set by a plugin or in your wp-settings.php file:

WP_POST_REVISIONS:

true (default), -1: store every revision
false, 0: do not store any revisions (except the one autosave per post)
(int) > 0: store that many revisions (+1 autosave) per post. Old revisions are automatically deleted.

设置这个变量为false或0的话，还是会保留一个历史版本的。

修改wp-config.php,增加一行：

.. sourcecode:: php

    define('WP_POST_REVISIONS', false );

清理数据库中版本历史
====================

1. 手工清理
2. 安装wp插件

自动保存的记录是如下记录：

.. sourcecode:: sql

    select * from `wp_posts` where `post_status` = 'auto-draft' ;

而版本记录是：

.. sourcecode:: sql

     select * from `wp_posts` where `post_status` = 'inherit';

手工保存的是：

.. sourcecode:: sql
          
      select * from `wp_posts` where `post_status` = 'draft' ;


删除草稿，自动保存，历史记录：

.. sourcecode:: sql

    select * from `wp_posts` where `post_status` = 'inherit' or \
    `post_status` = 'auto-draft' or `post_status` = 'draft';

    delete from `wp_posts` where `post_status` = 'inherit' or \
    `post_status` = 'auto-draft' or `post_status` = 'draft';


wordpress官方插件：`disable revisions`_

__ http://wordpress.org/extend/plugins/disable-revisions/


参考自月光博客 http://www.williamlong.info/archives/1416.html

这是由于WP自动保存版本修订历史引起的，禁用即可。但WP没有提供用户界面来设置是否禁用。

有老外写了这个禁用自动保存的插件，`文章在此<http://www.untwistedvortex.com/2008/06/27/adjust-wordpress-autosave-or-disable-it-completely/>`_

下载地址：<http://samm.dreamhosters.com/wordpress/plugins/disable-autosave.php>_

复制到 wp-content/plugins目录下，在控制台启用这个插件即可。


顺序排列：

涉及到4张表，都要更新。尝试使用循环解决，未遂。只得手工改。

下面的例子将id为108的记录修改id为7。

.. sourcecode:: sql

    update `wp_posts` set `id` = 7 where `id` = 108;
    update `wp_term_relationships` set `object_id` = 7 where `object_id` = 108;
    update `wp_postmeta` set `post_id` = 7 where `post_id` = 108;
    update `wp_comments` set `comment_post_ID` = 7 where `comment_post_ID` = 108;

