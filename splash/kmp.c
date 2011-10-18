#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int *generate_next(char *pat) {
    int len = strlen(pat);
    int *next = malloc( len * sizeof(int) );

    if(len>0) {
        next[0] = 0;
    }
    if(len>1) {
        next[1] = 1;
    }
    if(len<3) {
        return next;
    }
    int i=2;
    for(; i<len;i++) {
        int j=i-1;
        for(; j>0; j--) {
            int pos = next[j]-1;
            if(pat[pos] == pat[i-1]) {
                next[i] = next[j] + 1;
                break;
            }
        }
        if(j==0) {
            next[i] = 1;
        }
    }
    return next;
}

int kmp(char *string, char* pat, int *next) {
    int len_s = strlen(string);
    int len_p = strlen(pat);

    int i = 0;
    int j = 0;
    while ( i<len_s && j < len_p ) {
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
    return (j == len_p ? i-j : -1);
}

int main() {
    char *s = "hehe, hello, world! hehel.";
    char *p = "hehel";
    int *n = generate_next(p);
    int pos = kmp(s, p, n);
    printf("%d\n", pos);
    free(n);
    return 0;
}
