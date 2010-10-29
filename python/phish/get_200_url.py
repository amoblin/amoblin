# !/usr/bin/env python
# _*_ coding:utf-8 _*_

import os,sys
from httplib import HTTPConnection
from urlparse import urlparse
import urllib,urllib2

def main():
    f = open("url.txt","r")
    outfile = open("url_200.txt","w")
    for url in f.readlines():
        try:
            if get_status(url[:-1]) == 200:
                outfile.write(url)
        except:
            #os.system("chrome.exe " + '"' + url + '"')
            outfile.write("time_out: "+url)

    outfile.close()
    f.close()

def get_status(url):
    parts = urlparse(url)
    print url,":",
    host = parts.netloc
    loc  = parts.path
    if parts.query:
        loc += '?' + parts.query

    h = HTTPConnection(host)
    #h.set_debuglevel(1)
    #h.connect(host)
    h.request('GET', loc)
    status = h.getresponse().status
    #h.endheaders()

    #status, reason, headers =  h.getreply()
    #print '-' * 60
    #print 'status:', status
    #print 'reason:', reason
    #print 'headers:', headers
    print status
    return status

def get_sta(url):
    conn = urllib.urlopen("http://www.baidu.com")
    print conn
    return 

if __name__ == "__main__":
    main()
