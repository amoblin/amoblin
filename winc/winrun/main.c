#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
        switch(uMsg) {
        case WM_INITDIALOG:
                //MessageBox(hwnd, "Hello World!", "From MSYS", 0);
                break;

        case WM_CLOSE:
                // 要求系统关闭这个程序
                PostQuitMessage(0);
                break;
        case WM_COMMAND: {
        //case WM_KEYUP: {
                //MessageBox(NULL, wParam, "From MSYS", 0);
                //char buf[5];
                //itoa(wParam,buf,10);
                printf("%d\n",wParam);
                //MessageBox(NULL,buf,"消息提示",MB_OK|MB_ICONEXCLAMATION); 
                //MessageBox(NULL,wParam,"消息提示",MB_OK|MB_ICONEXCLAMATION); 
                switch(wParam) {
                //case IDOK:
                //case VK_RETURN:
                case 1: {
                        //WinExec("notepad.exe",SW_SHOW);
                        char command[20]="notepad.exe";
                        ShellExecute(hwnd,"open",command,"","", SW_SHOW );
                        EndDialog(hwnd,0);
                        break;
                }
                //case VK_ESCAPE:
                case 2: //Escape
                        PostQuitMessage(0);
                        break;
                }
                break;
            }
        }
        return 0;
}

// Windows系统的主函数
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nCmd)
{
        // 用这个系统函数创建我们刚刚绘制好的窗体IDD_DIALOG1，设置回叫函数为DlgProc
        //DialogBox(hInst, MAKEINTRESOURCE("CHAT_WINDOW"), 0, DlgProc);
        //DialogBox(hInst, MAKEINTRESOURCE(100), 0, DlgProc);
        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
        return 0;
}
