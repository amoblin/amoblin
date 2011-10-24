#!/usr/bin/env python
import xmlrpclib

blog_username = 'user'
blog_password = 'passwd'
blog_url = 'http://amoblin.sinaapp.com/xmlrpc.php'
have_tags = True
server = xmlrpclib.ServerProxy(blog_url)
push=0
post['title'] = '测试文章'
post['wp_slug'] = 'Slug'
post['wp_author_display_name'] = 'From'
post['categories'] = 'Categories'
if haveTags:
    post['mt_keywords'] = 'python'
post['description'] = '\n'.'text'
post['mt_text_more'] = ''
if push:
     post['post_status'] = 'publish'
else:
   post['post_status'] = 'draft'
datetime = 'Date'
strid = 'Post-Id'
if strid == '':
    strid = server.metaWeblog.newPost('', blog_username, blog_password, post, push)
