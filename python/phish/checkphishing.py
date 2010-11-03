#!/usr/bin/env python
# _*_ coding:utf-8 _*_

#############################
#Author:amoblin
#Environment:
#	1.python, pywin32.
#	2.chrome browser, add to environment path. extension suggestion:ultimate chrome flag, vrome.
#############################

import os,sys,threading,re
from win32com import client
import webbrowser
from cmdloop import *

#import win32clipboard as wincb
#import win32con

#import pythoncom,pyHook
#import SendKeys

def printl(msg):
    msg = str(msg)
    charset= sys.getdefaultencoding()
    if charset == 'ascii':#windows
        charset = 'gbk'
    try:
        print(msg.decode('utf-8').encode(charset))
    except exceptions.UnicodeEncodeError:
        print(msg)

def get_domain_name(url):
    url = 'http://www.alexa.com/search?q=' + url
    text = urlopen(url).read()
    #text = text.decode('utf-8')
    main_domain_name = re.findall(r'Site Information for.*<strong>(.*)</strong>',text)
    if main_domain_name: main_domain_name = main_domain_name[0]
    
    #alexa_rank = re.findall(r"Site Information for(.*)Details",text)
    #alexa_rank = re.findall(r"Alexa Traffic Rank:(.*)<a.*>(.*)</a>",text)
    #alexa_rank = re.findall(r'trafficstats">(.*)</a>',text)
    #if alexa_rank: alexa_rank = alexa_rank[0]
    #print alexa_rank
    return main_domain_name

def get_alexa_rank(url):
    try:
        data = urllib2.urlopen('http://data.alexa.com/data?cli=10&dat=snbamz&url=%s' % (url)).read()

        reach_rank = re.findall("REACH[^\d]*(\d+)", data)
        if reach_rank: reach_rank = reach_rank[0]
        else: reach_rank = -1

        popularity_rank = re.findall("POPULARITY[^\d]*(\d+)", data)
        if popularity_rank: popularity_rank = popularity_rank[0]
        else: popularity_rank = -1

        main_domain_name = re.findall('POPULARITY URL="(.*)/"', data)
        if main_domain_name: main_domain_name = main_domain_name[0]
        else: main_domain_name = get_domain_name(url)

        return main_domain_name,int(popularity_rank), int(reach_rank)

    #except (KeyboardInterrupt, SystemExit):
    #    raise
    except:
        return None,None,None

class Excel:
    def __init__(self):
        self.app = client.Dispatch("Excel.Application")
        self.app.Visible = 0
        self.app.DisplayAlerts = 0

    def sort(self):
        pass

class CLI(CommandLoop):
    PS1='Anti Phishing>'
    def __init__(self,Doc,start,end):
        self.aliasdict = {}
        self.Doc = Doc
        self.start = start
        self.end = end
        self.count = 0

    def _postCommand(self):
        if (self.count -1) == (self.end - self.start):
            self.gCmd(None,None)

    @aliases('g')
    @shorthelp('go on.')
    def gCmd(self,flags,args):
        raise HaltLoop

    @aliases('tr')
    @shorthelp('quit Hello environment.')
    def trCmd(self,flags,args):
        self.__writeExcel(args,1)

    @aliases('np')
    @shorthelp('mark the url as no phishing .')
    def npCmd(self,flags,args):
        self.__writeExcel(args,0)

    @aliases('se')
    @shorthelp('search the url with regular express.')
    def seCmd(self,flags,args):
        Sheet = self.Doc.ActiveSheet
        for j in range(self.start,self.end+1):
            if re.search(args[0],Sheet.Cells(j,1).Value):
                print j," ",Sheet.Cells(j,1).value.encode('gbk')," ",Sheet.Cells(j,2).Value," ",Sheet.Cells(j,3).Value

    @aliases('google')
    @shorthelp('use google search.')
    def googleCmd(self,flags,args):
        webbrowser.open_new_tab("http://www.google.com.hk/search?hl=zh-CN&newwindow=1&safe=strict&q=" + "+".join(args) + "&aq=f&aqi=&aql=&oq=&gs_rfai=")

    @aliases('alexa')
    @shorthelp('get alexa page rank.')
    def alexaCmd(self,flags,args):
        num = 0
        try:
            num = int(args[0])
        except:
            return
        print get_alexa_rank(self.Doc.ActiveSheet.Cells(num,1).Value)

    @aliases('exit')
    @shorthelp('exit the system.')
    def exitCmd(self,flags,args):
        self.Doc.Close(False)
        sys.exit()

    @aliases('h')
    @shorthelp('print the available command.')
    def hCmd(slef,flags,args):
        printl("np [序号-序号] 设置序号不是phishing")
        printl("tr [序号-序号] 设置序号可信任")
        printl("se [正则表达式] 搜索url")
        printl("google [关键词] 使用谷歌搜索")
        printl("alexa [序号] 查询该序号的alexa排名，主域名等")
        printl("g 继续下一组")
        printl("exit 退出程序")
        printl("h 打印此帮助")

    @aliases('reopen')
    @shorthelp('reopen the urls.')
    def reopenCmd(self,flags,args):
        Sheet = self.Doc.ActiveSheet
        for i in range(self.start,self.end + 1):
            url = Sheet.Cells(i,1).Value
            webbrowser.open_new_tab("http://" + url)

    
    def __writeExcel(self,args,flag):
        for arg in args:
            start= int(arg.split("-")[0])
            end = int(arg.split("-")[-1])
            if start < self.start:
                print "start:",start," is Out of Range [",self.start,",",self.end,"]"
            if end > self.end:
                print "end:",end," is Out of Range [",self.start,",",self.end,"]"
            else:
                Sheet = self.Doc.ActiveSheet
                for j in range(start,end+1):
                    url = Sheet.Cells(j,1).Value.encode("utf-8")
                    print url," ",Sheet.Cells(j,2).Value," ",Sheet.Cells(j,3).Value
                    Sheet.Cells(j,6).Value = 0    #mark none phishing.
                    if flag == 1:
                        Sheet.Cells(j,7).Value = 1    #mark none phishing.
                    self.count += 1

class AntiPhishing():
    def __init__(self):
        set_path="path=%path%;C:\\Documents and Settings\\Administrator\\Local Settings\\Application Data\\Google\\Chrome\\Application"
        os.system(set_path)
        self.cmd = 'chrome --disable-javascript "'

        self.urls = []
        self.welcome()
        self.main()
        #self.show_cata()

    def welcome(self):
        printl("Welcome to AntiPhishing. AntiPhishing makes you work more easily. More information please connect amoblin@gmail.com")
        printl("Usage:")
        printl("在当前目录下建立文件夹apl，将excle表放入apl文件夹内即可")
        printl("phishing列和trusted url列的默认值分别为 1 和 0")
        printl("np [序号-序号] 设置序号不是phishing")
        printl("tr [序号-序号] 设置序号可信任")
        printl("se [正则表达式] 搜索url")
        printl("google [关键词] 使用谷歌搜索")
        printl("alexa [序号] 查询该序号的alexa排名，主域名等")
        printl("g 继续下一组")
        printl("exit 退出程序")
        printl("h 打印帮助")

    def main(self):
        self.app = client.Dispatch("Excel.Application")
        self.app.Visible = 0
        self.app.DisplayAlerts = 0

        dir = "apl"
        type = "csv"

        FileList = os.listdir(dir)
        rr = re.compile( "\.%s$" %type , re.I )

        flag = 1
        for filename in FileList:
            if rr.search(filename):
                flag = 0
                filename = os.path.join(os.path.abspath(dir),filename)
                self.parse_excel(filename)
                #self.open_group(filename)
                #self.find_delete(filename)
        self.app.Quit()
        if flag:
            print "no excel file found.Please make sure there is an folder called 'apl' and the excel file in it."
        else:
            print "All Excel File Finished!"
        raw_input("Press Enter Key to Exit.")

    def find_delete(self,filename):
        print "Now check new file:",filename
        Doc = self.app.Workbooks.Open(filename)
        Sheet = Doc.ActiveSheet
        rows_count = Sheet.UsedRange.Rows.Count
        columns_count = Sheet.UsedRange.Rows.Count
        self.app.Range("A1:M" + str(rows_count)).Sort(Key1=self.app.Range("D1"),Order1=1)
        Doc.SaveAs(filename,6)	#save the sort result.
        print "All urls:",rows_count

        raw_input("Press Enter Key to continue...")


        i = 1
        np_url = open("np_url.txt","w")
        while not Sheet.Cells(i,6).value:
            url = Sheet.Cells(i,1).value
            print url
            np_url.write(url + "\n")
            i += 1
        np_url.close()
        

        delete_id = open("delete.txt","w")
        self.app.Range("A1:M" + str(i-1)).Sort(Key1=self.app.Range("D1"),Order1=1)
        Doc.SaveAs(filename,6)	#save the sort result.

        i = 1
        pw_id = Sheet.Cells(i,4).Value
        flag = 1

        while j <= rows_count+1:
            if pw_id is None:
                i += 1
                continue
            if pw_id == Sheet.Cells(i,4).Value:
                if Sheet.Cells(i,6).Value:
                    flag = 0
                i += 1
            else:
                if flag:
                    print int(pw_id)
                    delete_id.write(str(pw_id) + "\n")
                flag = 1
                pw_id = Sheet.Cells(i,4).Value

        delete_id.close()

    def parse_excel(self,filename):
        print "Now check new file:",filename

        Doc = self.app.Workbooks.Open(filename)
        Sheet = Doc.ActiveSheet
        rows_count = Sheet.UsedRange.Rows.Count
        columns_count = Sheet.UsedRange.Rows.Count
        print "All urls:",rows_count
        self.app.Range("A1:M" + str(rows_count)).Sort(Key1=self.app.Range("D1"),Order1=1)

        self.sort(Sheet,rows_count)

        Doc.SaveAs(filename,6)	#save the sort result.
        raw_input("Press Enter Key to continue...")
        begin = 1
        while Sheet.Cells(begin,6).Value is not None:
            begin+=1

        i = begin
        pw_id = Sheet.Cells(i,4).Value
        while i <= rows_count+1:
            if pw_id is None:
                i = i + 1
                continue
            if pw_id == Sheet.Cells(i,4).Value:
                url = Sheet.Cells(i,1).Value.encode("utf-8")
                try:
                    print i," ",url," ",Sheet.Cells(i,2).Value," ",Sheet.Cells(i,3).Value
                except:
                    pass

                Sheet.Cells(i,6).Value = 1  #mark phishing in default.
                Sheet.Cells(i,7).Value = 0  #mark untrusted in default.
                self.urls.append(url)
                if i - begin ==49:
                    pw_id = -1
                i=i+1
            else:
                try:
                    """use os.system to call chrome"""
                    commd = self.cmd + ' " "'.join(self.urls) + ' "'
                    th = threading.Thread(target=os.system,args=(commd,))
                    th.start()
                except:
                    """use webbrowser"""
                    for url in self.urls:
                        webbrowser.open_new_tab("http://" + url)
                print "opened",i-begin,"tabs",":",begin,"-",i-1,"with PW ID:",int(pw_id)
                CLI(Doc,begin,i-1).runLoop()
                Doc.SaveAs(filename,6)	#saved
                print "finished: ",i-1," / ",rows_count,"\n"
                begin = i
                self.urls = []
                pw_id = Sheet.Cells(i,4).Value
        Doc.Close(True)
        result = ""
        deleted = 0
        print "This Excel File Finished!"

    def sort(self,Sheet,rows_count):
        i = 1
        start = 1
        pwd = Sheet.Cells(start,4).Value
        while i <= rows_count:
            if pwd != Sheet.Cells(i,4).Value:
                self.app.Range("A" + str(start) + ":H" + str(i-1)).Sort(Key1=self.app.Range("A1"),Order1=1)
                start = i
                pwd = Sheet.Cells(start,4).Value
            i += 1
        self.app.Range("A" + str(start) + ":H" + str(rows_count)).Sort(Key1=self.app.Range("A1"),Order1=1)

    def open_group(self,filename):
        print "Now check new file:",filename
        Doc = self.app.Workbooks.Open(filename)
        Sheet = Doc.ActiveSheet
        rows_count = Sheet.UsedRange.Rows.Count
        columns_count = Sheet.UsedRange.Rows.Count
        self.app.Range("A1:M" + str(rows_count)).Sort(Key1=self.app.Range("D1"),Order1=1)
        Doc.SaveAs(filename,6)	#save the sort result.

        print "All urls:",rows_count

        raw_input("Press Enter Key to continue...")

        begin = 1
        while Sheet.Cells(begin,6).Value is not None:
            begin+=1

        start = begin
        for i in range(begin,rows_count):
            url = Sheet.Cells(i,1).Value
            if i - start == 20:
                print "\n\n open tabs: ",i-start,"/",i-1
                raw_input("Press Enter Key to continue.")
                self.urls = []
                start = i
                print "complete: ",i-1,"/",rows_count
                Doc.SaveAs(filename,6)	#saved
            print i," ",url," ",Sheet.Cells(i,2).Value," ",Sheet.Cells(i,3).Value
            self.urls.append(url)

        Doc.Close(True)
        print "This Excel File Finished!"

    def show_cata(self):
        cmd = 'plink root@10.0.0.72 -pw NIRTapl123 "cd /data/pw_verion;ls template*.xls|tail -n 1"'
        filename = os.popen(cmd).readline()[:-1]
        cmd = "scp2 root@10.0.0.72:/data/pw_verion/" + filename + " ." #need input password
        os.system(cmd)
        Doc = self.app.Workbooks.Open(filename)
        Sheet = Doc.ActiveSheet

if __name__ == "__main__":
    AntiPhishing()
