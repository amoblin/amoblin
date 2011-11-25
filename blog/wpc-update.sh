#!/bin/bash

id=`sed -n '4p' blog.rst| awk -F " " '{print $3}'`
../../wpc/blogpost.py -d rst --post-id ${id} update blog.rst
