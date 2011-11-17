#!/bin/bash

ln _vimrc ~/.vimrc
mkdir -p ~/.vim/backup

ln _screenrc ~/.screenrc

sudo cp gitconfig /etc/

sudo sh -c "cat _bashrc >> /etc/bashrc"

sudo sh -c "tail -4 inputrc >> /etc/inputrc"

../python/install.sh

#git config --global user.name amoblin

#git config --global user.email amoblin@163.com

#input method
#fcitx

#cmake gcc git

#download tool
#axel

#browser
#google chrome

#utils
#screen

#video
#mplayer

#virtualbox

#vim-full

