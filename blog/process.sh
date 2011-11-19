#!/bin/bash

sed -n '/<div /,/<\/body>/p' $1 | sed '$d' | tee /tmp/a | sed -n -e '2s/\(.*\)>\(.*\)<\(.*\)/\2/p'
sed -e '1,3d' -e '$d' /tmp/a > post.html

