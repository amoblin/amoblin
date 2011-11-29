#include <stdio.h>
#include <string.h>

void revert(char *str, char *out) {
    /*
       char *word = strtok(str, " ");
       printf("%s\n", word);
       while( word != NULL ) {
       printf("%s\n", word);
       strncpy( tmp, word, strlen(word) );
       word = strtok(NULL , "");
       }
     */
    char *tmp = (char *) malloc( sizeof(char) * (strlen(str)+1) );
    out = (char *) malloc( sizeof(char) * (strlen(str)+1) );
    strncpy( tmp, str, strlen(str)+1);

    char *stack[1024];
    int i = 0;

    char delims[] = " ";
    char *word = NULL;
    word = strtok( tmp, delims );
    while( word != NULL ) {
        stack[i] = word;
        i++;
        word = strtok( NULL, delims );
    }
    while(i>0) {
        i--;
        strncat( out, stack[i], strlen(stack[i]));
        strncat( out, " ", 1);
    }
    printf("%s\n", out);
}
