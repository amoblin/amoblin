#!/usr/bin/env python
#coding=utf-8
#读取pcap文件，解析相应的信息，为了在记事本中显示的方便，把二进制的信息
import struct
fpcap = open('test.pcap','rb')
ftxt = open('result.txt','w')
string_data = fpcap.read()
#pcap文件包头解析
pcap_header = {}
pcap_header['magic_number'] = string_data[0:4]
pcap_header['version_major'] = string_data[4:6]
pcap_header['version_minor'] = string_data[6:8]
pcap_header['thiszone'] = string_data[8:12]
pcap_header['sigfigs'] = string_data[12:16]
pcap_header['snaplen'] = string_data[16:20]
pcap_header['linktype'] = string_data[20:24]
#把pacp文件头信息写入result.txt
ftxt.write("Pcap文件的包头内容如下： \n")
for key in ['magic_number','version_major','version_minor','thiszone',
            'sigfigs','snaplen','linktype']:
    ftxt.write(key+ " : " + repr(pcap_header[key])+'\n')
          
#pcap文件的数据包解析
step = 0
packet_num = 0
packet_data = []
pcap_packet_header = {}
i =24
while(i<len(string_data)):
     
      #数据包头各个字段
      pcap_packet_header['GMTtime'] = string_data[i:i+4]
      pcap_packet_header['MicroTime'] = string_data[i+4:i+8]
      pcap_packet_header['caplen'] = string_data[i+8:i+12]
      pcap_packet_header['len'] = string_data[i+12:i+16]
      #求出此包的包长len
      packet_len = struct.unpack('I',pcap_packet_header['len'])[0]
      #写入此包数据
      packet_data.append(string_data[i+16:i+16+packet_len])
      i = i+ packet_len+16
      packet_num+=1
   
   
   
   
#把pacp文件里的数据包信息写入result.txt
for i in range(packet_num):
    #先写每一包的包头
    ftxt.write("这是第"+str(i)+"包数据的包头和数据："+'\n')
    for key in ['GMTtime','MicroTime','caplen','len']:
        ftxt.write(key+' : '+repr(pcap_packet_header[key])+'\n')
    #再写数据部分
    ftxt.write('此包的数据内容'+repr(packet_data[i])+'\n')
ftxt.write('一共有'+str(packet_num)+"包数据"+'\n')
      
ftxt.close()
fpcap.close()
