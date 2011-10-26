#!/usr/bin/env python
# -*- coding:utf-8 -*-

import cmd
from optparse import OptionParser

def print_list(list):
    i = 0
    color = ("", "\033[46m")
    for item in list:
        print("\033[34m%d\033[0m %s%s\033[0m" % (i, color[i%2], item) )
        i = i + 1

class cli_ui(cmd.Cmd):
    def __init__(self):
        cmd.Cmd.__init__(self)
        #self.intro="Welcome to amoblin's cli ui interface."
        self.prompt="\033[32mcli_ui>\033[0m "
        self.online = ['amoblin', 'whoomin', 'humin', 'csip', 'laputa']
        self.info = {}
        self.info['amoblin'] = "兴趣泛滥不宅男"
        self.info['whoomin'] = "小猫咪~"
        self.info['humin'] = "钻研课题中..."
        self.info['csip'] = "碳硅磷"
        self.info['laputa'] = "南山竹林"

    def default(self, line):
        print("未知命令: %s" % line)

    def do_ls(self, line):
        print_list(self.online)

    def do_info(self, line):
        print self.info[self.online[int(line)]]

    def help_exit(self):
        print("exit the system.")

    def do_exit(self, line):
        exit()

if __name__ == "__main__":
    cli = cli_ui()
    cli.cmdloop()
