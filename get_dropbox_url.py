#!/usr/bin/env python

import sys
import platform

def plat():
    if sys.platform.lower().startswith('linux'):
        arch = platform.machine()
        if (arch[0] == 'i' and
            arch[1].isdigit() and
            arch[2:4] == '86'):
            plat = "x86"
        elif arch == 'x86_64':
            plat = arch
        else:
            FatalVisibleError("Platform not supported")
        return "lnx.%s" % plat
    else:
        FatalVisibleError("Platform not supported")

# old version
VERSION_old = '1.1.45'
# current version
VERSION = '1.2.48'

url= 'http://www.dropbox.com/download?plat=%s' % plat()
print url

origin_url = 'https://dl-web.dropbox.com/u/17/dropbox-%s-%s.tar.gz' % (plat(), VERSION)
print origin_url
