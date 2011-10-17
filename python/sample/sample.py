#!/usr/bin/env python
# -*- coding:utf-8 -*-

import cmd
from optparse import OptionParser

class cli_ui(cmd.Cmd):
    def __init__(self):
        cmd.Cmd.__init__(self)
        #self.intro="Welcome to amoblin's cli ui interface."
        #self.prompt="cli_ui> "

    def help_exit(self):
        print("exit the system.")

    def do_exit(self, line):
        exit()

if __name__ == "__main__":
    cli = cli_ui()
    cli.cmdloop()
