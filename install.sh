#!/bin/bash

cp -ru bin ~

path=`python -c "import docutils; print docutils.__path__[0]"`
hg clone http://dev.pocoo.org/hg/pygments-main /tmp/pygments
sudo cp /tmp/pygments/external/rst-directive.py ${path}/parsers/rst/directives/rst_directive.py
