#!/bin/bash

title=`head -1 blog.rst`
wpc.py -d html -t "$title" post post.html
