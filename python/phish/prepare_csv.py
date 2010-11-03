#!/usr/bin/env python
#-*- coding:utf-8 -*-

#############################
#Author:amoblin
#Environment:
#	1.python, pywin32.
#	2.chrome browser, add to environment path. extension suggestion:ultimate chrome flag, vrome.
#############################

import os,sys,threading,re
import csv

def divide(filename):
    os.system("sort " + filename + "> tempfile")
    f1 = file("tempfile", 'rb')
    reader = csv.reader(f1)

    domain = ""
    diff_count = 0
    main_line = 0
    urlstr = []

    date=filename.split(".")[0]

    os.mkdir(date)
    f2 = file(os.path.join(date,"main.csv"),"wb")
    maincsv = csv.writer(f2)

    f3 = file(os.path.join(date,"pre.csv"),"wb")
    precsv = csv.writer(f3)

    
    for line in reader:
        domain = line[0].split('/')[0]
        break

    f1.seek(0)
    for line in reader:
        if domain == line[0].split('/')[0]:
            urlstr.append(line)
        else:
            if len(urlstr)> 5:
                #print "add to pre"
                diff_count += 1
                for row in urlstr:
                    precsv.writerow(row)
            else:
                #print "add to main"
                for row in urlstr:
                    main_line += 1
                    maincsv.writerow(row)
            urlstr = []
            urlstr.append(line)
            domain = line[0].split('/')[0]


    if len(urlstr)> 5:
        print "add to pre"
        diff_count += 1
        for row in urlstr:
            precsv.writerow(row)
    else:
        #print "add to main"
        for row in urlstr:
            main_line += 1
            maincsv.writerow(row)
            
    f1.close()
    f2.close()
    f3.close()
    info = str(main_line) + "-" + str(diff_count)
    print info
    f2 = file(os.path.join(date,info),"wb")
    f2.close()

if __name__ == "__main__":
    if len(sys.argv) == 2:
        divide(sys.argv[1])
    else:
        filename = raw_input("Please input file name:")
        divide(filename)
