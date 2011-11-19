#!/bin/bash

id=`sed -n '3p' blog.rst| awk -F " " '{print $3}'`
title=`head -1 blog.rst` 
wpc.py -d html --post-id ${id} -t "$title" update post.html
