#!/bin/bash

svnurl=https://pytool.googlecode.com/svn 
dirname=pytool

svnurl=https://gmbox.googlecode.com/svn
dirname=gmbox
username=amoblin@gmail.com

#svnurl=https://svn.sinaapp.com/myself
#dirname=myself
#username=amoblin@gmail.com

git svn clone ${svnurl} --username ${username} -t tags -T trunk -b branches ${dirname}
#git svn clone ${svnurl} --username ${username} ${dirname}

git co -b origin/branchname
