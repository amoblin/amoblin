#!/usr/bin/env python
# -*- coding:utf-8 -*-
# 键盘记录回放
# 

import pythoncom,pyHook
import SendKeys
import sys,time,threading
import win32clipboard as wincb
import win32con

class Auto:
    def __init__(self):
        self.flag = False
        self.play = True
        self.msg = "hello world!"

        hm = pyHook.HookManager()
        hm.KeyDown = self.onKeyboardEvent
        hm.HookKeyboard()
        pythoncom.PumpMessages()

    def sendmsg(self,msg):
        #wincb.OpenClipboard()
        #wincb.EmptyClipboard()
        #wincb.SetClipboardData(win32con.CF_TEXT, msg)  #复制文本内容到剪贴板，系统后台会返回内存地址
        #print wincb.GetClipboardData(win32con.CF_TEXT)  #'Hello World!'
        #wincb.CloseClipboard()
        SendKeys.SendKeys("""^v~""")


    def autoc(self):
        while self.flag:
            if self.play:
                self.sendmsg(self.msg)
            time.sleep(1)

    def onKeyboardEvent(self,event):
        if event.Alt and event.Key == 'F1':
            if self.flag:
                self.play = True
                self.msg = "Bye!"
                time.sleep(3)
                sys.exit()
            self.flag = True
            th = threading.Thread(target=self.autoc)
            th.start()
        elif event.Alt and event.Key == 'F2':
            if self.flag:
                self.play = not self.play
        return True

if __name__ == "__main__":
    Auto()
