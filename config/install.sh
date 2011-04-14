#!/bin/bash

ln _vimrc ~/.vimrc

ln _screenrc ~/.screenrc

sudo ln gitconfig /etc

sudo sh -c "tail -4 inputrc >> /etc/inputrc"
