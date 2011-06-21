#include <stdio.h>

int print_u(char *ustring, int i, int n)
{
    printf("%d: ", i);
    int k;
    for(k=0; k<n; k++) {
        //printf("%x ", ustring[i+k]);
        printf("%c", ustring[i+k]);
    }
    //printf("\n");
}

int main()
{
    FILE *fp = NULL;
    char *fname = "exercise.txt";
    fp = fopen(fname,"r");
    if(fp == NULL) {
        printf("file: %s does not exist, please check again.\n", fname);
        return 0;
    }
    char sentence[35];
    char out[15];
    int i,j;
    while(fgets(sentence, 35, fp) != NULL)
    {
        for(i=0,j=0;i<strlen(sentence);i++,j++) {
            if (sentence[i]<0xffffffc0) { //一位
                if (sentence[i] == '\n') {
                    continue;
                }
                print_u(sentence, i, 1);
                if (sentence[i] == 32) { //空格
                    out[j] = 0;
                }
            } else if( sentence[i] < 0xffffffe0 ) {  //2位
                print_u(sentence, i, 2);

                //dest = ( sentence[i] & 0x1F ) << 12;

                i = i + 1;
                out[j] = 0;
            } else if (sentence[i] < 0xfffffff0 ) {  //3位
                print_u(sentence, i, 3);

                unsigned short dest; /* two 2-byte variable */
                dest = ( sentence[i] & 0x0F ) << 12;
                //printf("%x\n", dest);
                dest |= (sentence[i+1] & 0x3f) << 6;
                //printf("%x\n", dest);
                dest |= (sentence[i+2] & 0x3f);
                printf("%x\n", dest);

                printf("%d\n", dest >> 8);
                printf("%d\n", dest & 0xff);

                i = i + 2;
                out[j] = 1;
            } else if (sentence[i] < 0xfffffff8 ) { //4位
                print_u(sentence, i, 4);
                i = i + 3;
            } else if (sentence[i] < 0xfffffffc ) { //5位
                print_u(sentence, i, 5);
                i = i + 4;
            } else {    //6位
                print_u(sentence, i, 6);
                i = i + 5;
            }

        }
    }
    fclose(fp);
    return 0;
}
