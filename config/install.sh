#!/bin/bash

ln _vimrc ~/.vimrc
mkdir -p ~/.vim/backup

ln _screenrc ~/.screenrc

sudo ln gitconfig /etc

cat _bashrc >> ~/.bashrc

sudo sh -c "tail -4 inputrc >> /etc/inputrc"

git config --global user.name amoblin

git config --global user.email amoblin@163.com
