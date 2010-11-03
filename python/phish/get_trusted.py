#!/usr/bin/env python
import sys,os,threading,urllib2,re,time
import shutil
from urllib import urlopen
from win32com import client
import webbrowser

def run_cmd(cmd):
    os.system(cmd)

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

        return main_domain_name,int(popularity_rank),int(reach_rank)

    #except (KeyboardInterrupt, SystemExit):
    #    raise
    except:
        return None,None,None


class AddWhite:
    def __init__(self):
        self.app = client.Dispatch("Excel.Application")
        self.app.Visible = 0
        self.app.DisplayAlerts = 0
        self.main()

    def main(self):
        dir = "white"
        type = "txt"
        FileList = os.listdir(dir)
        rr = re.compile( "\.%s$" %type , re.I )

        for filename in FileList:
            if rr.search(filename):
                file_name = os.path.join(os.path.abspath(dir),filename)
                #self.find_trusted(filename)
                self.get_domains(file_name)
                self.get_trusted(file_name + ".domain")
                self.anysc("white/" + filename + ".domain.white")

                #shutil.copy2(file,final_file)
                #os.remove(raw_file)
                #os.remove(file)

        self.app.Quit()
        print "wait 2 seconds to exit."
        time.sleep(2)

    def find_trusted(self,filename):
        print "Now check new file:",filename
        Doc = self.app.Workbooks.Open(filename)
        Sheet = Doc.ActiveSheet
        rows_count = Sheet.UsedRange.Rows.Count
        columns_count = Sheet.UsedRange.Rows.Count
        self.app.Range("A1:H" + str(rows_count)).Sort(Key1=self.app.Range("G1"),Order1=2)
        Doc.SaveAs(filename,1)	#save the sort result.
        print "All urls:",rows_count

        i = 1
        trusted_file = open("white\\trusted.txt","w")
        trusted_url = ""

        while Sheet.Cells(i,7).Value:
            trusted_url += Sheet.Cells(i,1).Value + "\n"
            i +=1
        trusted_file.write(trusted_url)    
        trusted_file.close()
        Doc.Close(False)
        print "This Excel File Finished!"

    def get_domains(self,filename):
        f = open(filename,"r")
        domains = []
        domains_str = ""
        for url in f.readlines():
            mdn,alexa_rank,reach_rank = get_alexa_rank(url)
            flag = 1
            for item in domains:
                if item == mdn:
                    flag = 0
                    break
            if flag:
                print "Add:",mdn
                domains.append(mdn)
                domains_str += str(mdn) + " " + str(alexa_rank) + " " + str(reach_rank) + "\n"
        f.close()
        
        domain = open(filename + ".domain","w")
        domain.write(domains_str)
        domain.close()

    def get_trusted(self,filename):
        print "get trusetd:"
        white_list = []
        domain = open(filename,"r")
        for url in domain.readlines():
            mdn,alexa_rank,reach_rank = url.split(" ")
            webbrowser.open_new_tab("http://" + mdn)
            print mdn,alexa_rank,reach_rank
            keyword = raw_input("White?(y/n):")
            if keyword == 'y':
                print "Add:",mdn
                white_list.append(mdn)
        domain.close()
        outfile = filename + ".white"
        f = open(outfile,"w")
        for item in white_list:
            print item
            f.write(item + "\n")
        f.close()
        return outfile

    def anysc(self,filename):
        cmd = 'scp ' + filename + ' root@10.0.0.72:/opt/trusted_dhr/new_url'
        os.system(cmd)
        os.system('ssh root@10.0.0.72 "/home/amoblin/add_trusted.sh"')

if __name__ == "__main__":
    AddWhite()
