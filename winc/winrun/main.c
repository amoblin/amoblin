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
                // Ҫ��ϵͳ�ر��������
                PostQuitMessage(0);
                break;
        case WM_COMMAND: {
        //case WM_KEYUP: {
                //MessageBox(NULL, wParam, "From MSYS", 0);
                //char buf[5];
                //itoa(wParam,buf,10);
                printf("%d\n",wParam);
                //MessageBox(NULL,buf,"��Ϣ��ʾ",MB_OK|MB_ICONEXCLAMATION); 
                //MessageBox(NULL,wParam,"��Ϣ��ʾ",MB_OK|MB_ICONEXCLAMATION); 
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

// Windowsϵͳ��������
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nCmd)
{
        // �����ϵͳ�����������Ǹոջ��ƺõĴ���IDD_DIALOG1�����ûؽк���ΪDlgProc
        //DialogBox(hInst, MAKEINTRESOURCE("CHAT_WINDOW"), 0, DlgProc);
        //DialogBox(hInst, MAKEINTRESOURCE(100), 0, DlgProc);
        DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc);
        return 0;
}
