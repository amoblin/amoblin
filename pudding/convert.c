#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

int print_u(char *ustring, int i, int n)
{
    if( !DEBUG ) {
        return 0;
    }
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
    char sentence[SEN_LEN * 3];  //语句长度最大值：18
    unsigned char in[DATA_SIZE][SEN_LEN * 2];  //无符号字符型数组，元素范围0～255.两个数字代表一个汉字。
    char out[DATA_SIZE][SEN_LEN];       //输出向量，1代表连续，0代表分词点。
    int i;    //utf8编码串游标；
    int j;  //输入向量游标；
    int k;  //输出向量游标。
    int t = 0;  //向量数组游标
    while(fgets(sentence, SEN_LEN * 3, fp) != NULL)
    {
        for(i = 0; i<SEN_LEN; i++) {
            in[t][i] = 0;
            in[t][i*2] = 0;
            out[t][i] = 0;
        }
        in[DATA_SIZE][SEN_LEN*2-1] = 0;
        i = 0;
        j = 0;
        k = 0;
        while(i<strlen(sentence)) {
            if (sentence[i]<0xffffffc0) { //一位
                if (sentence[i] == '\n') {
                    int s;
                    for(s=0; s<SEN_LEN * 2; s++) {
                        printf("%d ",in[t][s]);
                    }
                    printf("\n");
                    for(s=0;s<SEN_LEN;s++) {
                        printf("%d ",out[t][s]);
                    }
                    printf("\n");

                    i++;
                    continue;   //下一句
                }
                //print_u(sentence, i, 1);
                if (sentence[i] == 32) { //空格
                    out[t][k] = 0; //分词点
                    i++;//一位，所以游标加1
                }
            } else if( sentence[i] < 0xffffffe0 ) {  //2位
                print_u(sentence, i, 2);

                //dest = ( sentence[i] & 0x1F ) << 12;
                printf("2字节的utf8编码，看看怎么回事？\n");
                exit(0);

                out[t][k] = 0;
                i = i + 2;
            } else if (sentence[i] < 0xfffffff0 ) {  //3位
                print_u(sentence, i, 3);

                unsigned short dest; /* two 2-byte variable */
                dest = ( sentence[i] & 0x0F ) << 12;
                //printf("%x\n", dest);
                dest |= (sentence[i+1] & 0x3f) << 6;
                //printf("%x\n", dest);
                dest |= (sentence[i+2] & 0x3f);
                //printf("%x ", dest);

                out[t][k] = 1; //有字即1
                in[t][j] = dest >> 8;  //高位
                in[t][++j] = dest & 0xff;  //低位
                //printf("%d %d\n", in[t][j-1], in[t][j]);

                i = i + 3;
                j++;
            } else if (sentence[i] < 0xfffffff8 ) { //4位
                print_u(sentence, i, 4);
                i = i + 4;
                printf("4字节的utf8编码，看看怎么回事？\n");
                exit(0);
            } else if (sentence[i] < 0xfffffffc ) { //5位
                print_u(sentence, i, 5);
                i = i + 5;
                printf("5字节的utf8编码，看看怎么回事？\n");
                exit(0);
            } else {    //6位
                print_u(sentence, i, 6);
                i = i + 6;
                printf("6字节的utf8编码，看看怎么回事？\n");
                exit(0);
            }
            k++;    //输出向量游标增1
        }
        t++;        //向量数组游标增1
    }
    fclose(fp);

    FILE *vector_p = NULL;
    vector_p = fopen("sample.dat","wb");
    fwrite(in, IN_NODES, t, vector_p);
    fwrite(out, OUT_NODES, t, vector_p);
    fclose(vector_p);

    return 0;
}
