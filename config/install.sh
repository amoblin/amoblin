#!/bin/bash

ln -s `pwd`/.vimrc ~

ln -s `pwd`/.screenrc ~

sudo ln -s `pwd`/gitconfig /etc

sudo su
tail -4 inputrc >> /etc/inputrc
