#!/bin/bash

ln .vimrc ~

ln .screenrc ~

sudo ln gitconfig /etc

sudo su
tail -4 inputrc >> /etc/inputrc
