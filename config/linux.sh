#!/bin/bash

## 下载apt-spy软件包
#http://packages.debian.org/search?keywords=apt-spy

# 或者使用http://ubuntu9.com 寻找

dir=`python -c "import docutils; print docutils.__path__[0]"`

hg clone http://dev.pocoo.org/hg/pygments-main /tmp/pygments
cp /tmp/pygments/external/rst-directive.py ${dir}/parsers/rst/directives/rst_directive.py

## 文档编写
#ubuntu:
sudo apt-get install python-setuptools
sudo easy_install docutils pygments

