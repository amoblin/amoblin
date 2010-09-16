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
                } else if ( (p->vkCode == 0x00ba) && ((p->flags & LLKHF_ALTDOWN)!=0) ) {    //;
                    ShellExecute(NULL,"open","C:\\Documents and Settings\\Administrator\\Local Settings\\Application Data\\Google\\Chrome\\Application\\chrome.exe","","", SW_SHOWMAXIMIZED );
                } else if ( (p->vkCode == 0x00bc) && ((p->flags & LLKHF_ALTDOWN)!=0) ) {    //,
                    ShellExecute(NULL,"open","explorer.exe","D:\\MSYS\\home\\Administrator\\received","", SW_SHOW );
                } else if ( (p->vkCode == 0x00be) && ((p->flags & LLKHF_ALTDOWN)!=0) ) {    //.
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
        static char subkey[] = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
        static char vname[] = "ShortCut";
        static char exefile[] = "D:\\MSYS\\home\\Administrator\\Projects\\amoblin\\winc\\quickrun\\shortcut.exe";
        ULONG dType = REG_SZ, len = 0;
        HKEY hKey;
        RegOpenKeyEx(HKEY_LOCAL_MACHINE,subkey,0,KEY_SET_VALUE|KEY_QUERY_VALUE,&hKey);//打开。
        if (RegQueryValueEx(hKey, vname, 0, &dType, NULL, &len)) { //如果没有RunMyProg，
            RegSetValueEx(hKey, vname, 0, REG_SZ, (LPBYTE)exefile, strlen(exefile)+1); //就加上。
        }
        RegCloseKey(hKey); //关闭。 

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
