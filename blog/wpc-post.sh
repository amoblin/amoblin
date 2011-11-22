#!/bin/bash

title=`sed -n '2p' blog.rst`
../../wpc/blogpost.py -d html -t "$title" post _post.html
