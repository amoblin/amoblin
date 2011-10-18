#include <stdio.h>
#include <string.h>

int pmatch(char *string, char *pat) {
    int i,j;
    int len_s = strlen(string);
    int len_p = strlen(pat);
    int bp = len_s - len_p + 1;
    for( i=0; i<bp; i++) {
        for( j=0; j<len_p; j++) {
            if (string[i+j] != pat[j]) {
                break;
            }
        }
        if (j == len_p) {
            return i;
        }
    }
    return -1;
}

int kmp(char *string, char* pat) {
    int i,j;
    int len_s = strlen(string);
    int len_p = strlen(pat);
    int bp = len_s - len_p + 1;
    i = 0;
    j = 0;
    int next[5];
    next[0] = 0;
    next[1] = 1;
    next[2] = 1;
    next[3] = 2;
    next[4] = 3;
    while ( i<bp && j < len_p ) {
        if( string[i] == pat[j] ) {
            i++;
            j++;
            continue;
        }
        if( j > 0 ) {
                j = next[j] - 1;
        } else {
            i++;
        }
    }
    if( j== len_p) {
        return i-j;
    } else {
        return -1;
    }
}

int main() {
    char *s = "hehe, hello, world! hehel.";
    char *p = "hehel";
    int pos = kmp(s, p);
    printf("%d\n", pos);
    return 0;
}
