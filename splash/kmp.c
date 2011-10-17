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
}

int main() {
    char *s = "hehe, hello, world! hehel.";
    char *p = "hehel";
    int pos = pmatch(s, p);
    printf("%d\n", pos);
    return 0;
}
