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

void Findfile(char * filepath); //�����ļ����ĺ���(�ݹ����)

int _tmain()
{
 clock_t start,end; //��������ʱ�����ֹʱ��
 char filepath[MAX] = "c:\\Program Files\\"; //���ó�ʼ·��
 level = 0;  //��ʼ��ε���0
 filecount = 0 ;  //��ʼ�ļ�����Ϊ0
 start = clock(); //���ÿ�ʼ
 Findfile(filepath); //������Һ���
 end = clock();  //ʱ����ֹ
 printf("%s �ļ�����Ϊ %d\n",filepath,filecount);
 printf("Interval = %.2f seconds\n",(double)(end-start)/(double)CLOCKS_PER_SEC); //����ܾ���ʱ��
 getchar();
 return filecount;
}


void Findfile(char * filepath)
{
 WIN32_FIND_DATA FindFileData;  //���ز����ļ���Ϣ
 HANDLE hFind;    //�����ļ����
 char temppath[MAX];   //����·��
 char tempfile[MAX];   //�����ļ�������·����
 ++level;    //�ݹ麯����μ�1
 strcpy(tempfile,filepath);  //Ϊ��ǰ·�����ϲ���ͨ���
 strcat(tempfile,"*");
 if ( hFind = FindFirstFile(tempfile, &FindFileData) )
 {
  if ( strcmp( FindFileData.cFileName,".") && strcmp( FindFileData.cFileName,"..") ) //��ӡ�ļ���
  {
   printf ("The file found is %s\n", FindFileData.cFileName);
   ++filecount;  //�ļ�������1
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

   ++filecount;  //�ļ�������1
  }
  else if ( strcmp( FindFileData.cFileName,".") && strcmp( FindFileData.cFileName,"..") )  //���ҵ����ļ�ΪĿ¼������ݹ�
  {
   temppath[0] = '\0';
   strcat(temppath,filepath);
   strcat(temppath,FindFileData.cFileName);
   strcat(temppath,"\\");
   Findfile( temppath );
  }
 }
 --level;  //��ǰ��������
 FindClose(hFind); //�ر��ļ����
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
                            //MessageBox(NULL,abspath,"��Ϣ��ʾ",MB_OK|MB_ICONEXCLAMATION); 
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
