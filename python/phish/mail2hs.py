#! /usr/bin/env python
# _*_ coding:utf-8 _*_

#############################
#Author:amoblin
#############################

#import pcap
#import dpkt
#from dpkt.ethernet import Ethernet
import time,os
import struct
import poplib,email,smtplib
import binascii
import email.mime.multipart
import email.iterators
import email.generator
import email.utils

try:
    from email.MIMEText import MIMEText
except:
    from email.mime import text as MIMEText

import re,urllib2
from subprocess import Popen, PIPE

class Mail2HS:
    def __init__(self,user,passwd,sub,label=""):
        self.label = label
        self.username = user   #must be google mail.
        self.password = passwd
        self.mail_address = "shaojunyi@huaweisymantec.com"
        self.subject = sub

        PipeOut = os.popen("dir attach\*.* /B")
        FileList = PipeOut.readlines()
        PipeOut = os.popen("cd")
        CurDic = PipeOut.readline()
        CurDic = CurDic[:-1] + "\\attach\\"
        #print "Current Directory:",CurDic
        for filename in FileList:
            print "attachments:",len(FileList)
            filename = CurDic + filename[:-1]
            print filename
            self.send_mail(filename)
        print "All Finished!"
        raw_input("Press Enter Key to exit.")

    def send_mail(self,filename):
        """发送邮件"""
        mailServer=smtplib.SMTP('smtp.gmail.com',587)
        mailServer.ehlo()
        mailServer.starttls()
        mailServer.ehlo()
        mailServer.login(self.username,self.password)

        main_msg = email.MIMEMultipart.MIMEMultipart()

        #text_msg = email.MIMEText.MIMEText(body,_charset='utf-8')
        #main_msg.attach(text_msg)

        att = email.MIMEText.MIMEText(open(filename,'rb').read(), 'base64', _charset='utf-8')
        att["Content-Type"] = 'application/octet-stream'
        att['Content-Disposition'] = 'attachment;filename=' + os.path.basename(filename)

        main_msg.attach(att)

        charset="utf-8"

        main_msg['from']= self.label + " < " + self.username + " >"

        main_msg['to']=self.mail_address

        main_msg['date']=time.ctime()
        main_msg['subject']=email.Header.Header(self.subject,charset)

        mailServer.sendmail(main_msg['from'],main_msg['to'],main_msg.as_string())
        mailServer.close()

if __name__ == "__main__":
    sub = time.strftime("%Y-%m-%d")
    sub += "数据"
    user = "amoblin@gmail.com"
    passwd = "asdfghjkl"
    m2 = Mail2HS(user,passwd,sub,"崔贵林")
