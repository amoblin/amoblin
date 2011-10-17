#!/usr/bin/env python

from ctypes import *
import os
libtest = cdll.loadLibrary(os.getcwd() + '/ofetion.so');
