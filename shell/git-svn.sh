#!/bin/bash

svnurl=https://pytool.googlecode.com/svn 
dirname=pytool
username=amoblin

svnurl=https://svn.sinaapp.com/myself
dirname=myself
username=amoblin@gmail.com

git svn clone ${svnurl} --username ${username} -t tags -T trunk -b branches ${dirname}
