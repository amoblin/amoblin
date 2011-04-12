#!/bin/bash

ln .vimrc ~

ln .screenrc ~

sudo ln gitconfig /etc

sudo sh -c "tail -4 inputrc >> /etc/inputrc"
