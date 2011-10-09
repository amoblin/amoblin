#!/usr/bin/env python
# -*- coding:utf8 -*-

import urllib2, urllib, sys
from HTMLParser import HTMLParser

def generate_bailu_short_url(url):
    params = urllib.urlencode({'url':url})   
    dest_url="http://bai.lu/api?%s" % params
    response = urllib2.urlopen(dest_url)
    result = response.read()
    data = eval(result)
    short_url = data['url']
    if (data['status'] == 'ok'):
        return data['url'].replace('\\','')
    else:
        return None

class Ganji_Parser(HTMLParser):
    def __init__(self, link):
        HTMLParser.__init__(self)
        self.begin = False
        self.pos = ''
        self.contents = []
        self.content = []
        self.href = ''
        self.link = link

    def handle_starttag(self, tag, attrs):
        if tag == 'div':
            for name, value in attrs:
                if name == "class" and value == "list":
                    self.begin = True

        if not self.begin:
            return

        if tag == 'p':
            self.pos = 'con_3'
        elif tag == 'i':
            self.pos = 'time'
        elif tag == 'a':
            for name, value in attrs:
                if name == 'target' and value == '_blank':
                    self.pos = 'con_1'
                elif name == 'href':
                    if not self.href:
                        self.href = 'http://bj.ganji.com%s' % value
                elif name == 'class' and value == 'adds':
                    self.pos = 'con_adds'

        elif tag == 'span':
            for name, value in attrs:
                if name == 'class' and value == 'f_c_red':
                    self.pos = 'con_keyword'

    def handle_endtag(self, tag):
        if not self.begin:
            return

        if tag == 'div':
            self.begin = False
        elif tag == 'i':
            self.time = 0
        elif tag == 'p':
            if self.link:
                self.content.append(generate_bailu_short_url(self.href))
                print " ".join(self.content)
            print " ".join(self.content)
            self.contents.append(self.content)
            self.content = []
            self.href = ''

    def handle_data(self, data):
        if not self.begin:
            return

        data = data.strip()

        if self.pos == 'time':
            self.content.append(data)
        elif self.pos == 'con_1':
            self.content.append(data)
        elif self.pos == 'con_keyword':
            self.content.append(data)
        elif self.pos == 'con_adds':
            self.content.append(data)
        elif self.pos == 'con_3':
            self.content.append(data)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        link = False
    else:
        link = True
    
    ganji = Ganji_Parser(link)
    ganji.feed(urllib2.urlopen("http://bj.ganji.com/shouji/p5/_iphone4/").read())
    if not ganji.link:
        while len(ganji.contents):
            item = ganji.contents.pop()
            print " ".join(item)

