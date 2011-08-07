#include <string.h>
#include <stdlib.h>

int print_u(char *ustring, int i, int n)
{
    int k;
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

int utf8_to_unicode(char *sentence, unsigned char in[], float out[])
{
    int i = 0;    //utf8编码串游标；
    int j = 0;  //输入向量游标；
    int k = 0;  //输出向量游标。
    while(i<strlen(sentence)) {
        int length;
        get_utf8_bytes(sentence[i], &length);
        /*
        printf("%d: ", i);
        print_u(sentence, i, length);
        printf("\n");
        */
        unsigned short dest;//2字节
        switch(length) {
            case 1:
                if (sentence[i] == '\n') {
                    int s;
                    for(s=0; s<IN_NODES; s++) {
                        printf("%d ",in[s]);
                    }
                    printf("\n");
                    for(s=0; s<OUT_NODES; s++) {
                        printf("%f ",out[s]);
                    }
                    printf("\n");
                } else if (sentence[i] == 32) { //空格
                    out[k] = 0.1; //分词点
                }
                break;
            case 2:

                //dest = ( sentence[i] & 0x1F ) << 12;
                printf("2字节的utf8编码，看看怎么回事？\n");
                exit(0);

                out[k] = 0.1;
                break;

            case 3:
                dest = ( sentence[i] & 0x0F ) << 12;
                //printf("%x\n", dest);
                dest |= (sentence[i+1] & 0x3f) << 6;
                //printf("%x\n", dest);
                dest |= (sentence[i+2] & 0x3f);
                //printf("%x ", dest);

                out[k] = 0.9; //有字即1
                in[j] = dest >> 8;  //高位
                in[++j] = dest & 0xff;  //低位
                //printf("%d %d\n", in[t][j-1], in[t][j]);
                j++;
                break;
            case 4:
            case 5:
            case 6:
                printf("%d字节的utf8编码，看看怎么回事？\n", length);
                exit(0);
            default:    //can never happen.
                break;
        }
        i = i + length;
        k++;    //输出向量游标增1
    }
}

int get_data_size()
{
    return 6;
}
