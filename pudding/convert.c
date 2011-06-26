#include <stdio.h>
#define SEN_LEN 18  //分词语句最大长度

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
    char sentence[SEN_LEN * 3];  //语句长度最大值：18
    unsigned char in[SEN_LEN * 2];  //无符号字符型数组，元素范围0～255.两个数字代表一个汉字。
    char out[SEN_LEN];       //输出向量，1代表连续，0代表分词点。
    int i;    //utf8编码串游标；
    int j;  //输入向量游标；
    int k;  //输出向量游标。
    while(fgets(sentence, SEN_LEN * 3, fp) != NULL)
    {
        for(i = 0;i<SEN_LEN;i++) {
            in[i] = 0;
            out[i] = 0;
        }
        i = 0;
        j = 0;
        k = 0;
        while(i<strlen(sentence)) {
            if (sentence[i]<0xffffffc0) { //一位
                if (sentence[i] == '\n') {
                    //TODO:写入
                    int s;
                    for(s=0;s<SEN_LEN;s++) {
                        printf("%d ",in[s]);
                    }
                    printf("\n");
                    for(s=0;s<SEN_LEN;s++) {
                        printf("%d ",out[s]);
                    }
                    printf("\n");
                    i++;
                    continue;   //下一句
                }
                //print_u(sentence, i, 1);
                if (sentence[i] == 32) { //空格
                    out[k] = 0; //分词点
                    i++;
                }
            } else if( sentence[i] < 0xffffffe0 ) {  //2位
                print_u(sentence, i, 2);

                //dest = ( sentence[i] & 0x1F ) << 12;
                printf("2字节的utf8编码，看看怎么回事？\n");

                out[k] = 0;
                i = i + 2;
            } else if (sentence[i] < 0xfffffff0 ) {  //3位
                print_u(sentence, i, 3);

                unsigned short dest; /* two 2-byte variable */
                dest = ( sentence[i] & 0x0F ) << 12;
                //printf("%x\n", dest);
                dest |= (sentence[i+1] & 0x3f) << 6;
                //printf("%x\n", dest);
                dest |= (sentence[i+2] & 0x3f);
                printf("%x ", dest);

                out[k] = 1; //有字即1
                in[j] = dest >> 8;  //高位
                in[++j] = dest & 0xff;  //低位
                printf("%d %d\n", in[j-1], in[j]);

                i = i + 3;
                j++;
            } else if (sentence[i] < 0xfffffff8 ) { //4位
                print_u(sentence, i, 4);
                i = i + 4;
            } else if (sentence[i] < 0xfffffffc ) { //5位
                print_u(sentence, i, 5);
                i = i + 5;
            } else {    //6位
                print_u(sentence, i, 6);
                i = i + 6;
            }
            k++;
        }
    }
    fclose(fp);
    return 0;
}
