=============================
wordpress blog id不连续的解决
=============================
.. id: 8


参考自 `月光博客`__

__ http://www.williamlong.info/archives/1416.html

这是由于WP自动保存版本修订历史引起的，禁用即可。但WP没有提供用户界面来设置是否禁用。

.. more

安装禁用自动保存的wp插件
========================

有老外写了这个禁用自动保存的插件， `文章在此`__

__ http://www.untwistedvortex.com/2008/06/27/adjust-wordpress-autosave-or-disable-it-completely/

`插件下载地址`__

__ <http://samm.dreamhosters.com/wordpress/plugins/disable-autosave.php>

复制到 wp-content/plugins目录下，在控制台启用这个插件即可。

删除历史冗余记录
================

删除草稿记录，自动保存记录，版本变迁记录：

.. sourcecode:: sql

    select * from `wp_posts` where `post_status` = 'inherit' or `post_status` = 'auto-draft' or `post_status` = 'draft';

    delete from `wp_posts` where `post_status` = 'inherit' or `post_status` = 'auto-draft' or `post_status` = 'draft';

将id顺序排列
============

涉及到4张表，都要更新。尝试使用循环解决，未遂。只得手工改。

下面的例子将id为108的记录修改id为7。

.. sourcecode:: sql

    update `wp_posts` set `id` = 7 where `id` = 108;
    update `wp_term_relationships` set `object_id` = 7 where `object_id` = 108;
    update `wp_postmeta` set `post_id` = 7 where `post_id` = 108;
    update `wp_comments` set `comment_post_ID` = 7 where `comment_post_ID` = 108;


新建博客仍有问题。新博客的id并不小！
