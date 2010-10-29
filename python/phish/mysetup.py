#!/usr/bin/env python
# mysetup.py
from distutils.core import setup
import py2exe
#import shutil

#shutil.rmtree("build", ignore_errors=True)
#shutil.rmtree("dist", ignore_errors=True)

#includes=["encodings","encodings.*"]
#includes=[]
#excludes = ["pywin", "pywin.debugger", "pywin.debugger.dbgcon",
#            "pywin.dialogs", "pywin.dialogs.list",
#            "Tkconstants","Tkinter","tcl"
#            ]

options={'py2exe':
        {"compressed":1,
            "optimize":2,
            "ascii":1,
            "packages":"encodings",
            #"includes":includes,
            #"excludes":excludes,
            "bundle_files":1
            }
        }
setup(
    options = options,
    zipfile = None,
    #console=[{"script":"checkphishing.py","icon_resources":[(1,"icon_antiPhishing.ico")]}],
    console=[{"script":"precheck.py","icon_resources":[(1,"icon_antiPhishing.ico")]}],
    #console=[{"script":"get_trusted.py","icon_resources":[(1,"icon_antiPhishing.ico")]}],
    #console=[{"script":"test.py","icon_resources":[(1,"wireshark.ico")]}]
    #windows=[{"script":"sk.py","icon_resources":[(1,"autokey.ico")]}]
    #windows=[{"script":"pyshortcut.py","icon_resources":[(1,"autokey.ico")]}]
    #windows=[{"script":"pyrun.py","icon_resources":[(1,"autokey.ico")]}]
    #windows=[{"script":"test.py","icon_resources":[(1,"autokey.ico")]}]
    #console=[{"script":"mail2hs.py","icon_resources":[(1,"autokey.ico")]}]
    #windows=[{"script":"autotsm.py","icon_resources":[(1,"autokey.ico")]}]
    )
