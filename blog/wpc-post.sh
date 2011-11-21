#!/bin/bash

title=`head -1 blog.rst`
../../wpc/blogpost.py -d html -t "$title" post post.html
