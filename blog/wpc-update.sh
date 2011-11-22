#!/bin/bash

id=`sed -n '4p' blog.rst| awk -F " " '{print $3}'`
title=`sed -n '2p' blog.rst` 
echo $title
../../wpc/blogpost.py -d html --post-id ${id} -t "$title" update _post.html
