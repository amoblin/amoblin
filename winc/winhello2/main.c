#include <windows.h>
#include "resource.h"

// Windows��Ϣ���ƣ��μ�����Ľ������ľ���--��Ϣ�ؽк�����
INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
        // ����Ϣ�������ж�
        switch(uMsg) {
        // ����Ǵ��ڳ�ʼ����Ϣ
        case WM_INITDIALOG:
                // ����������һ���汾�е�Hello World
                MessageBox(hwnd, "Hello World!", "From MSYS", 0);
                break;

        // ������ڱ��ر�
        case WM_CLOSE:
                // Ҫ��ϵͳ�ر��������
                PostQuitMessage(0);
                break;
        }

        // Ĭ�Ϸ���0
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
