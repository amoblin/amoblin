#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "resource.h"

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
            printf("compare with %s:",command);
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
                        //WinExec("notepad.exe",SW_SHOW);
                        char command[32];
                        GetDlgItemText(hwnd, INPUT_AREA, command, 32);
                        char abspath[256];
                        if(GetCommandPath(command,abspath)) {
                            //MessageBox(NULL,abspath,"消息提示",MB_OK|MB_ICONEXCLAMATION); 
                            ShellExecute(hwnd,"open",abspath,"","", SW_SHOW );
                        } else {
                            ShellExecute(hwnd,"open",command,"","", SW_SHOW );
                        }
                        EndDialog(hwnd,0);
                        break;
                }
                //case VK_ESCAPE:
                case IDCANCEL: //Escape
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
        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
        return 0;
}
