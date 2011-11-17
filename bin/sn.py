#!/usr/bin/env python
# -*- coding:utf8 -*-

import urllib2, re, sys
import httplib, urllib

def get_info(sn):
    data = {}
    data['sn'] = sn
    conn = httplib.HTTPSConnection("selfsolve.apple.com")
    conn.request("POST", "/agreementWarrantyDynamic.do", urllib.urlencode(data))
    res = conn.getresponse()
    print res.read()
    conn.close()

def get_info_1(sn):
    url = "https://selfsolve.apple.com/agreementWarrantyDynamic.do?sn=%s" % sn
    print url
    con = urllib2.urlopen(url)
    print con.read()

def usage():
    print "usage: %s [sn]" % sys.argv[0]

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()
        exit(0)

    url = "https://selfsolve.apple.com/warrantyChecker.do?sn=%s" % sys.argv[1]
    content = urllib2.urlopen(url).read()

    purchase_date_re = '"PURCHASE_DATE":"(.+?)"'
    end_date_re = '"COV_END_DATE":"(.+?)"'
    prod_descr = '"PROD_DESCR":"(.+?)"'
    purchase_date = re.findall(purchase_date_re, content)
    if not purchase_date:
        print "错误的序列号: ", sys.argv[1]
        exit(0)
    purchase_date = purchase_date[0]
    end_date = re.findall(end_date_re, content)[0]
    prod_descr = re.findall(prod_descr, content)[0]
    print "产品描述: ", prod_descr
    print "购买日期: ", purchase_date
    print "到期日期: ", end_date
    
    #get_info(sys.argv[1])
