#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include <windows.h>
#include "resource.h"

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
    FILE *fp;
    fp = fopen("quickrun.ini","r");
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



LRESULT CALLBACK hook_proc( int code, WPARAM wParam, LPARAM lParam )
{
  static long ctrl_cnt = 0;
  static bool mmode = false;
  static DWORD time;

  KBDLLHOOKSTRUCT*  kbd = (KBDLLHOOKSTRUCT*)lParam;

  //if (  code < 0 ||   (kbd->flags & 0x10) // ignore injected events
   //  ) return CallNextHookEx( thehook, code, wParam, lParam );

  long ret = 1; // by default I swallow the keys
  if (  mmode  ) { // macro mode is ON
    if (  WM_KEYDOWN == wParam  )
      PostMessage(mainwnd, WM_MCR_ACCUM, kbd->vkCode, 0);

    if (  WM_KEYUP == wParam  )
      switch (kbd->vkCode) {
        case VK_ESCAPE:
          mmode = false;
          keys.removeall();
          PostMessage(mainwnd, WM_MCR_HIDE, 0, 0);
          break;

        case VK_RETURN:
          PostMessage(mainwnd, WM_MCR_EXEC, 0, 0);
          break;

        case VK_LCONTROL:
          mmode = false;
          PostMessage(mainwnd, WM_MCR_HIDE, 0, 0);
          PostMessage(mainwnd, WM_MCR_EXEC, 0, 0);
          break;
      }

    /* Which non printable keys allow passing? */
    switch( kbd->vkCode ) {
      case VK_LCONTROL:
      case VK_CAPITAL:
      case VK_LSHIFT:
      case VK_RSHIFT:
        //ret = CallNextHookEx( thehook, code, wParam, lParam );
    }
  }
  else { // macro mode is OFF
    /* Ctrl pressed */
    if (  kbd->vkCode == VK_LCONTROL && WM_KEYDOWN == wParam  ) {
      ctrl_cnt = 1;
      time = kbd->time;
    }

    /* Prevent ctrl combinations to activate macro mode */
    if (  kbd->vkCode != VK_LCONTROL  )
      ctrl_cnt = 0;

    /* Ctrl released */
    if (  ctrl_cnt == 1 && WM_KEYUP == wParam  ) {
      if (  kbd->time - time > 40  ) {
        mmode = true;
        PostMessage(mainwnd, WM_MCR_SHOW, 0, 0);
      }
    }

    //ret = CallNextHookEx( thehook, code, wParam, lParam ); // let it pass
  }

  return ret;
}

int KeyboardMonitor()
{
    HHOOK thehook = SetWindowsHookEx( WH_KEYBOARD_LL, hook_proc, hwnd, 0 );

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
                        KeyboardMonitor();
                        //EndDialog(hwnd,0);
                        break;
                }
                //case VK_ESCAPE:
                case IDCANCEL: //Escape
                        KeyboardMonitor();
                        //PostQuitMessage(0);
                        break;
                }
                break;
            }
        }
        return 0;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nCmd)
{
        KeyboardMonitor();
        //DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
        return 0;
}
