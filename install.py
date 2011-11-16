#!/usr/bin/env python
# -*- coding:utf-8 -*-

## 下载apt-spy软件包
#http://packages.debian.org/search?keywords=apt-spy

# 或者使用http://ubuntu9.com 寻找

import sys
import docutils

packages = []
eggs = []

docutils_path = docutils.__path__

#hg clone http://dev.pocoo.org/hg/pygments-main /tmp/pygments
#cp /tmp/pygments/external/rst-directive.py ${dir}/parsers/rst/directives/rst_directive.py

## 文档编写
packages.append("python-setuptools")
eggs.append("docutils")
eggs.append("pygments")

# workrave
packages.append("workrave")

def install():
    '''deb安装，rpm安装，python eggs安装等'''
    sys.


if __name__ == "__main__":
    install()
