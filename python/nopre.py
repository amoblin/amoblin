#!/usr/bin/env python

import sys
import xml.dom.minidom as minidom
import codecs

def usage():
    pass

def convert_pre(filename):
    global dom
    dom = minidom.parse(filename)
    root = dom.documentElement
    for pre in root.getElementsByTagName('pre'):
        convert(pre)
        pre.tagName='div'
        pre.setAttribute('id','codeText')
        pre.setAttribute('class','codeText')
    xml_str = dom.toxml()
    xml_str = xml_str.replace('nbsp','&nbsp;')
    f = codecs.open("b.html",'w','utf-8');
    #writer = codecs.lookup('utf-8')[3](f)
    #dom.writexml(writer,encoding='utf-8')
    #f.close()

    #f2 = open('b.thml','w')
    #xml_str = f2.read()
    f.write(xml_str)
    f.close()

def convert(ele):
    if ele.nodeType == ele.ELEMENT_NODE:
        tmp = list(ele.childNodes)
        for child in tmp:
            convert(child)
    elif ele.nodeType == ele.TEXT_NODE:
        xml_str = ele.toxml().replace(' ','nbsp')
        xml_str = xml_str.replace('\n','<br/>\n')
        xml_str = "<data>" + xml_str + "</data>"
        xml_str = xml_str.encode('utf-8')
        new_ele = minidom.parseString(xml_str)
        nodes = list(new_ele.documentElement.childNodes)
        for node in nodes:
            ele.parentNode.insertBefore(node,ele)
        ele.parentNode.removeChild(ele)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()
        sys.exit(0)
    convert_pre(sys.argv[1])
