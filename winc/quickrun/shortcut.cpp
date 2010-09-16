/* kbhook.cpp */

//#define _WIN32_WINNT    0400
//#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <shellapi.h>

#define bool BOOL

DWORD   g_main_tid = 0;
HHOOK   g_kb_hook   = 0;

bool CALLBACK con_handler (DWORD)
{
        PostThreadMessage (g_main_tid, WM_QUIT, 0, 0);
        return TRUE;
};

LRESULT CALLBACK kb_proc (int code, WPARAM w, LPARAM l)
{
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)l;
        const char *info = NULL;
        if (code == HC_ACTION) {
            switch(w) {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
                if ( (p->vkCode == 0x00de) && ((p->flags & LLKHF_ALTDOWN)!=0) ) {
                    ShellExecute(NULL,"open","D:\\MSYs\\mintty.bat","","", SW_SHOW );
                }
                    break;
            case WM_KEYUP:
            case WM_SYSKEYUP:
                    break;
            }
        }

        // always call next hook
        return CallNextHookEx (g_kb_hook, code, w, l);
};

int main (void)
{
        g_main_tid = GetCurrentThreadId ();
        SetConsoleCtrlHandler (&con_handler, TRUE);
        g_kb_hook = SetWindowsHookEx ( WH_KEYBOARD_LL, &kb_proc, GetModuleHandle (NULL), 0);
        if (g_kb_hook == NULL)
        {
            fprintf (stderr, "SetWindowsHookEx failed with error %d\n", ::GetLastError ());
            return 0;
        };

        // 消息循环是必须的，想知道原因可以查msdn
        MSG msg;
        while (GetMessage (&msg, NULL, 0, 0)) {
            TranslateMessage (&msg);
            DispatchMessage (&msg);
        };
        UnhookWindowsHookEx (g_kb_hook);
        return 0;
};
