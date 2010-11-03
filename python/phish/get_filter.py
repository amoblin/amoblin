#! /usr/bin/env python
# _*_ coding:utf-8 _*_

#############################
#Author:amoblin
#############################

import pcap
import dpkt
from dpkt.ethernet import Ethernet
import time,os
import struct
import poplib,email,smtplib
import binascii
import webbrowser,cmd


import re,urllib2
from subprocess import Popen, PIPE
def get_ip_address():
	return re.search('\d+\.\d+\.\d+\.\d+',Popen('ipconfig', stdout=PIPE).stdout.read()).group(0)
	#print "本机的公网IP地址为：" + re.search('\d+\.\d+\.\d+\.\d+',urllib2.urlopen("http://www.7qiao.cn/ip.php").read()).group(0)

def formattime(t): #日期字段格式化 
    return time.strftime('%c',time.gmtime(t+8*3600)) 

class Wireshark:
    def __init__(self):
        self.pc=pcap.pcap()    #注，参数可为网卡名，如eth0
        self.ip = get_ip_address()
        filter = 'host ' + self.ip + " and not arp"
        self.pc.setfilter(filter)    #设置监听过滤器
        self.filtercontent = []

        self.get_filter()
        raw_input("Now you can prepare to capture packet.")
        #self.capture()

    def get_filter(self):
        timestamp = time.time()
        mark_time = timestamp
        for ptime,pdata in self.pc:
            p=Ethernet(pdata)
            try:
                recv_len=len(pdata)
                if recv_len == 102 and pdata[42]== chr(02) and pdata[101] == chr(03):
                    print struct.unpack('>I',pdata[49:53])[0]
                    print '登陆了'
                elif recv_len == 55:
                    print struct.unpack('>I',pdata[49:53])[0]
                    print '登陆了'

                #sStr1 = p.data.data.data
                srcip='%d.%d.%d.%d'%tuple(map(ord,list(p.data.src)))
                ip='%d.%d.%d.%d'%tuple(map(ord,list(p.data.dst)))

                #print '========================================================='
                #print 'time = ',formattime(ptime)
                #print p.data.__class__.__name__ #maybe is IP
                #print p.data.data.__class__.__name__    #maybe is TCP
                #print '%s------->%s,PORT:%d' %(srcip,ip,p.data.data.dport)
                #print 'data = ',sStr1



                if srcip != self.ip and self.judge_ip(srcip):
                    print formattime(ptime),p.data.data.__class__.__name__,p.data.__class__.__name__,p.data.data.dport,srcip,ip,"\n"
                    self.filtercontent.append(srcip)
                    timestamp = ptime
                if ip != self.ip and self.judge_ip(ip):
                    print formattime(ptime),p.data.data.__class__.__name__,p.data.__class__.__name__,p.data.data.dport,srcip,ip,"\n"
                    self.filtercontent.append(ip)
                    timestamp = ptime
            except:
                pass

            dure = ptime-timestamp
            print dure
            if dure > 60:
                f = open("filter.txt",'w')
                filter = str(ptime - mark_time) + "s\n"
                filter += "host " + self.ip + " and not arp"
                for ip in self.filtercontent:
                    filter += " and not ip dst or src " + ip
                print filter
                f.write(filter)
                f.close()
                break;

            #t=binascii.hexlify(pdata) 
            #print t 
    def capture(self):
        f = open("filter.txt","r")
        filter = f.readlines()[1]
        print filter
        filter = "host 10.0.0.135 and not arp and not ip dst or src 61.142.238.88"
        pc=pcap.pcap()    #注，参数可为网卡名，如eth0
        pc.setfilter(filter)    #设置监听过滤器
        for ptime,pdata in pc:
            p=Ethernet(pdata)
            try:
                recv_len=len(pdata)
                if recv_len == 102 and pdata[42]== chr(02) and pdata[101] == chr(03):
                    print struct.unpack('>I',pdata[49:53])[0]
                    print '登陆了'
                elif recv_len == 55:
                    print struct.unpack('>I',pdata[49:53])[0]
                    print '登陆了'

                #sStr1 = p.data.data.data
                srcip='%d.%d.%d.%d'%tuple(map(ord,list(p.data.src)))
                ip='%d.%d.%d.%d'%tuple(map(ord,list(p.data.dst)))

                print '========================================================='
                print 'time = ',formattime(ptime)
                print p.data.__class__.__name__ #maybe is IP
                print p.data.data.__class__.__name__    #maybe is TCP
                print '%s------->%s,PORT:%d' %(srcip,ip,p.data.data.dport)
                print 'data = ',sStr1

            except:
                pass

    def judge_ip(self,ip):
        flag = 1
        for list_ip in self.filtercontent:
            if ip == list_ip:
                flag = 0
        return flag

class Mail2HS:
    def __init__(self,sub):
        self.username = "whoomin@gmail.com"   #must be google mail.
        self.password = "a2b3c4d5"
        self.mail_address = "shaojunyi@huaweisymantec.com"
        #self.mail_address = "amoblin@gmail.com"
        self.subject = sub

        PipeOut = os.popen("dir attach\*.* /B")
        FileList = PipeOut.readlines()
        PipeOut = os.popen("cd")
        CurDic = PipeOut.readline()
        CurDic = CurDic[:-1] + "\\attach\\"
        #print "Current Directory:",CurDic
        for filename in FileList:
            filename = CurDic + filename[:-1]
            print filename
            self.send_mail(filename)

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

        main_msg['from']= "胡敏 <" + self.username + ">"

        main_msg['to']=self.mail_address

        main_msg['date']=time.ctime()
        main_msg['subject']=email.Header.Header(self.subject,charset)

        mailServer.sendmail(main_msg['from'],main_msg['to'],main_msg.as_string())
        mailServer.close()


class CLI(cmd.Cmd):
    def __init__(self):
        cmd.Cmd.__init__(self)
    def default(self,line):
        print "unknown command."
        exit()

if __name__ == "__main__":
    sub = raw_input("subject:")
    m2 = Mail2HS(sub.decode("GBK").encode('utf-8'))
    #Wireshark()
