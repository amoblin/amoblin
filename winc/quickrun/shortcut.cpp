/* kbhook.cpp */

//#define _WIN32_WINNT    0400
//#define STRICT
#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <shellapi.h>

#define bool BOOL
#define MAXLENGTH 1024

DWORD   g_main_tid = 0;
HHOOK   g_kb_hook   = 0;

bool control_key=0;

bool CALLBACK con_handler (DWORD)
{
        PostThreadMessage (g_main_tid, WM_QUIT, 0, 0);
        return TRUE;
};

int getvkcode(char *ch)
{
    if (!strcmp(ch,";"))
        return 0x00ba;
    else if (!strcmp(ch,"'"))
        return 0x00de;
    else if (!strcmp(ch,","))
        return 0x00bc;
    else if (!strcmp(ch,"."))
        return 0x00be;
    else if (!strcmp(ch,"/"))
        return 0x00bf;
    else if (!strcmp(ch,"a"))
        return 0x0041;
    else if (!strcmp(ch,"F1"))
        return 0x0070;
    else if (!strcmp(ch,"F2"))
        return 0x0071;
    else if (!strcmp(ch,"F3"))
        return 0x0072;
    else if (!strcmp(ch,"F4"))
        return 0x0073;
    else if (!strcmp(ch,"F5"))
        return 0x0074;
    else if (!strcmp(ch,"F6"))
        return 0x0075;
    else if (!strcmp(ch,"F7"))
        return 0x0076;
    else if (!strcmp(ch,"F8"))
        return 0x0077;
    else if (!strcmp(ch,"F9"))
        return 0x0078;
    else if (!strcmp(ch,"F10"))
        return 0x0079;
    else if (!strcmp(ch,"F11"))
        return 0x007a;
    else if (!strcmp(ch,"F12"))
        return 0x007b;
    else
        return 0x0000;
}

int GetAction(PKBDLLHOOKSTRUCT p)
{
    FILE *fp;
    fp = fopen("shortcut.ini","r");
    if (fp == NULL) {
        printf("Cannot open this file.\n");
        return 0;
    } else {
        printf("read shortcut.ini.\n");
    }
    char buf[MAXLENGTH];
    char KeyboardCode[100];
    char CommandPath[100];
    while(fgets(buf,MAXLENGTH,fp)) {
        bool flag = 1;
        char *ptr = strchr(buf,'=');
        if(ptr) {
            memset(KeyboardCode,0,strlen(KeyboardCode));
            strncpy(KeyboardCode,buf,ptr-buf);
            //printf("compare with %s:\n",KeyboardCode);
            char *token = strtok(KeyboardCode,"+");
            while(token != NULL) {
                //printf("the key is: %s\n",token);
                if(!strcmp(token,"ALT")) {
                    flag = 0;
                    if ((p->flags & LLKHF_ALTDOWN)!=0)
                        flag = 1;
                } else if (p->vkCode == getvkcode(token) && flag) {
                        strcpy(CommandPath,ptr+sizeof(char));
                        char *ptr = strchr(CommandPath,'\n');
                        if(ptr) {
                            *ptr = 0;
                        }
                        printf("execute %s:",CommandPath);
                        ShellExecute(NULL,"open",CommandPath,"","", SW_SHOW );
                    }
                token = strtok(NULL,"+");
            }
        }
    }
    fclose(fp);
    return 0;
}

LRESULT CALLBACK kb_proc (int code, WPARAM w, LPARAM l)
{
        PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)l;
        printf ("code is %d, vkCode [%04x], scanCode [%04x]\n", code, p->vkCode, p->scanCode);
        if (code == HC_ACTION) {
            switch(w) {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
                    if(p->vkCode == 0x00a2) {
                        control_key= 1;
                    } else if((p->vkCode == 76) && control_key) {
                        keybd_event(VK_F4,0,0,0);
                        keybd_event(VK_F4,0,KEYEVENTF_KEYUP,0);
                    }
                    printf("Get Action.\n");
                    GetAction(p);
                    break;
            case WM_KEYUP:
                    if(p->vkCode == 0x00a2) {
                        control_key= 0;
                    }
                    break;
            case WM_SYSKEYUP:
                    break;
            }
        }
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
