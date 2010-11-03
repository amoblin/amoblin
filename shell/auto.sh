#!/bin/bash

cd /phish/trusted

ls *.txt > list_new
new_file="new_file_`date "+%F"`"
diff list list_new | grep '> '|awk {'print $2'} > $new_file
mv list_new list
rm url
#new_file="new_file_2010-09-16"
for file in `cat $new_file`
do
    echo $file
    echo `wc -l $file`
    cat $file |awk '$3 != 7 && $3!=20101 {print $2}' >> url
done
