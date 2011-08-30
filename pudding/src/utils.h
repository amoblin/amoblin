#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>


int print_u(char *ustring, int i, int n)
{
    int k;
    printf("%d: ", i);
    for(k=0; k<n; k++) {
        printf("%c", ustring[i+k]);
    }
}

int get_utf8_bytes(char code, int *length)
{
    if( code < 0xffffffc0) { //一位
        *length = 1;
    } else if( code < 0xffffffe0 ) {  //2位
        *length = 2;
    } else if ( code < 0xfffffff0 ) {  //3位
        *length = 3;
    } else if ( code < 0xfffffff8 ) { //4位
        *length = 4;
    } else if ( code < 0xfffffffc ) { //5位
        *length = 5;
    } else {    //6位
        *length = 6;
    }
    return 0;
}

int utf8_to_unicode(char *sentence, unsigned char in[], double out[])
{
    int i = 0;    //utf8编码串游标；
    int j = 0;  //输入向量游标；
    int k = 0;  //输出向量游标。
    while(i<strlen(sentence)) {
        int length;
        get_utf8_bytes(sentence[i], &length);
        print_u(sentence, i, length);
        unsigned short dest;//2字节
        switch(length) {
            case 1:
                if (sentence[i] == '\n') {
                    printf("输入向量:");
                    int s;
                    for(s=0; s<UNI_LEN; s++) {
                        printf("%d ",in[s]);
                    }
                    printf("\n输出向量:");
                    for(s=0; s<SEN_LEN; s++) {
                        printf("%f ",out[s]);
                    }
                    printf("\n");
                } else if (sentence[i] == 32) { //空格
                    out[k] = 0.1; //分词点
                }
                break;
            case 3:
                dest = ( sentence[i] & 0x0F ) << 12;
                //printf("%x\n", dest);
                dest |= (sentence[i+1] & 0x3f) << 6;
                //printf("%x\n", dest);
                dest |= (sentence[i+2] & 0x3f);
                //printf("%x ", dest);

                in[j] = dest >> 8;  //高位
                in[++j] = dest & 0xff;  //低位
                printf("%d %d\t", in[j-1], in[j]);
                j++;
                k++;    //输出向量游标增1
                break;
            case 2:
            case 4:
            case 5:
            case 6:
                printf("%d字节的utf8编码，看看怎么回事？\n", length);
                exit(0);
            default:    //can never happen.
                break;
        }
        i = i + length;
    }
    in[j] = '\0';
    printf("\n");
}

int get_data_size(FILE *fp)
{
    char buffer[49];
    int data_size=0;
    while(fgets(buffer,sizeof(buffer),fp) != NULL) {
        int i=0;
        int sen_len = strlen(buffer);
        int j;
        for(j=0; j< sen_len;j++) {
            if (buffer[j] == 32) {
                i++;
            }
        }
        int utf8_len = sen_len - i -1;

        data_size += utf8_len/3 - 3;
        //printf("%d\n",data_size);
    }
    fseek(fp, 0, SEEK_SET);
    return data_size;
}
