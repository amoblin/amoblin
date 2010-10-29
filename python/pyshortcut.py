#!/usr/bin/env python
# -*- coding:utf-8 -*-

#use win32clipboard to use the *nix like copy and paste.

import pythoncom,pyHook
#import SendKeys
import os,time,threading,subprocess
#import win32clipboard as wincb
#import win32con
import Tkinter

class PyRun:
    def __init__(self):
        self.root = Tkinter.Tk()
        self.entry = Tkinter.Entry(self.root,width=20)
        self.entry.pack(expand=1,fill=Tkinter.X,pady=10,padx=15)
        self.entry.bind("<Return>",self.ParseCmd)
        self.entry.focus_set()
        self.center_window()
        self.root.mainloop()
    def ParseCmd(self,event):
        cmd = self.entry.get()
        if cmd == "chrome":
            subprocess.Popen([cmd])
        elif cmd == "mintty":
            subprocess.Popen(["d:\\msys\\bin\mintty","-e","d:\\msys\\bin\\bash.exe","--login","-i"])
        elif cmd == "explorer":
            subprocess.Popen(["d:\\msys\\bin\mintty","-e","d:\\msys\\bin\\bash.exe","--login","-i"])

    def center_window(self):
        ws = self.root.winfo_screenwidth()
        hs = self.root.winfo_screenheight()
        x = (ws/2)
        y = (hs/2)
        self.root.geometry('+%d+%d' % (x, y))

class Shortcut:
    def __init__(self):
        hm = pyHook.HookManager()
        hm.KeyDown = self.onKeyboardEvent
        hm.HookKeyboard()
        pythoncom.PumpMessages()

    def onKeyboardEvent(self,event):
        if event.Alt and event.Key == 'Return':
            #os.spawnv(os.P_NOWAIT,r"d:\\msys\\bin\mintty",("-e","d:\\msys\\bin\\bash.exe","--login","-i"))
            commd="start d:\\msys\\bin\mintty -e d:\\msys\\bin\\bash.exe --login -i"
            th = threading.Thread(target=os.system,args=(commd,))
            th.start()
            #subprocess.Popen([commd])
            #subprocess.Popen(["d:\\msys\\bin\mintty","-e","d:\\msys\\bin\\bash.exe","--login","-i"])
        elif event.Alt and event.Key == "F2":
            #th = threading.Thread(target=PyRun)
            #th.start()
            commd = "pyrun"
            th = threading.Thread(target=os.system,args=(commd,))
            th.start()
        elif event.Alt and event.Key == "Home":
            pass
        return True

if __name__ == "__main__":
    Shortcut()
