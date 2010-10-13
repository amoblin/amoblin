#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
#include <string.h>
#include <time.h>

#include <windows.h>
#include "resource.h"

#define bool BOOL

#define MAX 1000
int level = 0;
int filecount = 0;

void Findfile(char * filepath); //查找文件核心函数(递归查找)

int _tmain()
{
 clock_t start,end; //保存起终时间和终止时间
 char filepath[MAX] = "c:\\Program Files\\"; //设置初始路径
 level = 0;  //初始层次等于0
 filecount = 0 ;  //初始文件总数为0
 start = clock(); //设置开始
 Findfile(filepath); //进入查找函数
 end = clock();  //时钟终止
 printf("%s 文件总数为 %d\n",filepath,filecount);
 printf("Interval = %.2f seconds\n",(double)(end-start)/(double)CLOCKS_PER_SEC); //获得总经过时间
 getchar();
 return filecount;
}


void Findfile(char * filepath)
{
 WIN32_FIND_DATA FindFileData;  //返回查找文件信息
 HANDLE hFind;    //返回文件句柄
 char temppath[MAX];   //保存路径
 char tempfile[MAX];   //保存文件名（带路径）
 ++level;    //递归函数层次加1
 strcpy(tempfile,filepath);  //为当前路径加上查找通配符
 strcat(tempfile,"*");
 if ( hFind = FindFirstFile(tempfile, &FindFileData) )
 {
  if ( strcmp( FindFileData.cFileName,".") && strcmp( FindFileData.cFileName,"..") ) //打印文件名
  {
   printf ("The file found is %s\n", FindFileData.cFileName);
   ++filecount;  //文件总数加1
  }
 }
 else
 {
  return ;
 }
 while( FindNextFile(hFind,&FindFileData) )
 {
  if ( FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY && strcmp( FindFileData.cFileName,".") && strcmp( FindFileData.cFileName,"..") )
  {
   //printf ("%s\%s\n", filepath, FindFileData.cFileName);

   ++filecount;  //文件总数加1
  }
  else if ( strcmp( FindFileData.cFileName,".") && strcmp( FindFileData.cFileName,"..") )  //查找到的文件为目录，进入递归
  {
   temppath[0] = '\0';
   strcat(temppath,filepath);
   strcat(temppath,FindFileData.cFileName);
   strcat(temppath,"\\");
   Findfile( temppath );
  }
 }
 --level;  //当前层查找完毕
 FindClose(hFind); //关闭文件句柄
}

#define MAXLENGTH 1024

int GetCommandPath(char *cmd, char *abspath)
{
    printf("%s\n",cmd);
    FILE *fp = fopen("quickrun.ini","r");
    if (fp == NULL) {
        printf("Cannot open this file.\n");
        return;
    }
    char buf[MAXLENGTH];
    char command[100];
    while(fgets(buf,MAXLENGTH,fp)) {
        char *ptr = strchr(buf,'=');
        if(ptr) {
            memset(command,0,strlen(command));
            strncpy(command,buf,ptr-buf);
            //printf("compare with %s:",command);
            if(!strcmp(command,cmd)) {
                strcpy(abspath,ptr+sizeof(char));
                char *ptr = strchr(abspath,'\n');
                if(ptr) {
                    *ptr = 0;
                }
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}

INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
        switch(uMsg) {
        case WM_INITDIALOG:
                //MessageBox(hwnd, "Hello World!", "From MSYS", 0);
                break;

        case WM_CLOSE:
                PostQuitMessage(0);
                break;
        case WM_COMMAND: {
        //case WM_KEYUP: {
                //printf("%d\n",wParam);
                switch(LOWORD(wParam)) {
                case IDOK: {
                //case VK_RETURN:
                //case 1: {
                        char command[32];
			
			int filecount = _tmain();
			sprintf(command,"%d",filecount);
			MessageBox(hwnd, command, "From MSYS", 0);

                        GetDlgItemText(hwnd, INPUT_AREA, command, 32);
                        char abspath[256];
                        if(GetCommandPath(command,abspath)) {
                            //MessageBox(NULL,abspath,"消息提示",MB_OK|MB_ICONEXCLAMATION); 
                            ShellExecute(hwnd,"open",abspath,"","", SW_SHOW );
                        } else {
                            ShellExecute(hwnd,"open",command,"","", SW_SHOW );
                        }
                        //KeyboardMonitor();
                        EndDialog(hwnd,0);
                        break;
                }
                //case VK_ESCAPE:
                case IDCANCEL: //Escape
                        //KeyboardMonitor();
                        PostQuitMessage(0);
                        break;
                }
                break;
            }
        }
        return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nCmd)
{
        //KeyboardMonitor();
        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
        return 0;
}
