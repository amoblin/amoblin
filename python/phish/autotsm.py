#!/usr/bin/env python
# -*- coding:utf-8 -*-

import SendKeys
import sys,time,threading
import win32api,win32gui,win32con

def click_at_pos(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,0,0,0,0)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,0,0,0,0)

time.sleep(8)

#SendKeys.SendKeys("""
#    {LWIN}d
#""")


    #{PAUSE .25}
    #r
    #"C:\Program{SPACE}Files\Huawei\TSM{SPACE}Agent\\bin\WinGUI.exe"{ENTER}
    #{PAUSE 10}
#tsm = win32gui.FindWindow(None,'TSM Agent')
#win32gui.ShowWindow(tsm,win32con.SW_RESTORE)

click_at_pos(700,618)

SendKeys.SendKeys("""
    {PAUSE 1}
    GHN@huawei*{ENTER}
    %{F4}
    {PAUSE 5}
    {ESC}
""")

click_at_pos(1172,125)
