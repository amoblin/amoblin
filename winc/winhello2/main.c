#include <windows.h>
#include "resource.h"

// Windows消息机制（参见下面的讲述）的精髓--消息回叫函数。
INT_PTR CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
        // 对消息类别进行判断
        switch(uMsg) {
        // 如果是窗口初始化消息
        case WM_INITDIALOG:
                // 这是我们上一个版本中的Hello World
                MessageBox(hwnd, "Hello World!", "From MSYS", 0);
                break;

        // 如果窗口被关闭
        case WM_CLOSE:
                // 要求系统关闭这个程序
                PostQuitMessage(0);
                break;
        }

        // 默认返回0
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
