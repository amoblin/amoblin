import os,sys,time
import Tkinter,subprocess

class PyRun:
    def __init__(self):
        self.root = Tkinter.Tk()
        self.entry = Tkinter.Entry(self.root,width=20)
        self.entry.pack(expand=1,fill=Tkinter.X,pady=10,padx=15)
        #self.entry.bind("<Return>",self.ParseCmd)
        self.entry.focus_set()
        #self.center_window()
        self.root.mainloop()
    def ParseCmd(self,event):
        cmd = self.entry.get()
        if cmd == "chrome":
            subprocess.Popen([cmd])
        elif cmd == "mintty":
            subprocess.Popen(["d:\\msys\\bin\mintty","-e","d:\\msys\\bin\\bash.exe","--login","-i"])
        elif cmd == "explorer":
            subprocess.Popen(["d:\\msys\\bin\mintty","-e","d:\\msys\\bin\\bash.exe","--login","-i"])

        sys.exit()

    def center_window(self):
        ws = self.root.winfo_screenwidth()
        hs = self.root.winfo_screenheight()
        x = (ws/2)
        y = (hs/2)
        self.root.geometry('+%d+%d' % (x, y))

if __name__ == "__main__":
    PyRun()
