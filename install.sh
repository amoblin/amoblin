#!/bin/bash

cp -ru bin ~

path=`python -c "import docutils; print docutils.__path__[0]"`
hg clone http://dev.pocoo.org/hg/pygments-main /tmp/pygments
sudo cp /tmp/pygments/external/rst-directive.py ${path}/parsers/rst/directives/rst_directive.py

sudo patch -p1 ${path}/parsers/rst/directives/rst_directive.py < patch/rst_directive.patch
#
##dropbox patch
#
version='1.2.48'
sudo sed -i 's/urlopen(.*)/urlopen(os.path.join(os.path.expanduser("~"), "dropbox-%s-%s.tar.gz" % (plat(), "'"$version"'")))/' `which dropbox`

