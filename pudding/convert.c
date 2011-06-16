#include <stdio.h>
int main()
{
    FILE *fp = NULL;
    char *fname = "exercise.txt";
    fp = fopen(fname,"r");
    if(fp == NULL) {
        printf("file: %s does not exist, please check again.\n", fname);
        return 0;
    }
    char sentence[30];
    while(fgets(sentence, 10, fp) != NULL)
        printf("%s", sentence);
    fclose(fp);
    return 0;
}
