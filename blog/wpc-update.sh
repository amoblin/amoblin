#!/bin/bash

id=`head -1 blog.rst| awk -F " " '{print $3}'`
wpc.py -d html --post-id ${id} -t `sed -n '4p' blog.rst` update post.html
