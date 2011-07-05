#define SEN_LEN 54  //分词语句最大长度,一个汉字占3个utf8字节
#define DATA_SIZE 1000  //学习数据的上限

#define IN_NODES 36     //输入层节点数,一个汉字占2个unicode字节
#define OUT_NODES 18     //输出层节点数,汉字的个数
#define HIDDEN_NODES 49   //隐含层节点数
#define REAL_DATA_SIZE 6 //实际学习数据量


#define LOOP_MAX 100000   //最大循环次数
#define LEARN_RATE  0.09 //学习率
#define PRECISION 0.05  //精度

#define DEBUG 1

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
    printf("\n");
}

int utf8_to_unicode(char *sentence, unsigned char in[], char out[])
{
    int i = 0;    //utf8编码串游标；
    int j = 0;  //输入向量游标；
    int k = 0;  //输出向量游标。
    while(i<strlen(sentence)) {
        if (sentence[i]<0xffffffc0) { //一位
            if (sentence[i] == '\n') {
                int s;
                for(s=0; s<IN_NODES; s++) {
                    printf("%d ",in[s]);
                }
                printf("\n");
                for(s=0; s<OUT_NODES; s++) {
                    printf("%d ",out[s]);
                }
                printf("\n");

                i++;
                continue;   //下一句
            }
            //print_u(sentence, i, 1);
            if (sentence[i] == 32) { //空格
                out[k] = 0; //分词点
                i++;//一位，所以游标加1
            }
        } else if( sentence[i] < 0xffffffe0 ) {  //2位
            //print_u(sentence, i, 2);

            //dest = ( sentence[i] & 0x1F ) << 12;
            printf("2字节的utf8编码，看看怎么回事？\n");
            exit(0);

            out[k] = 0;
            i = i + 2;
        } else if (sentence[i] < 0xfffffff0 ) {  //3位
            //print_u(sentence, i, 3);

            unsigned short dest; /* two 2-byte variable */
            dest = ( sentence[i] & 0x0F ) << 12;
            //printf("%x\n", dest);
            dest |= (sentence[i+1] & 0x3f) << 6;
            //printf("%x\n", dest);
            dest |= (sentence[i+2] & 0x3f);
            //printf("%x ", dest);

            out[k] = 1; //有字即1
            in[j] = dest >> 8;  //高位
            in[++j] = dest & 0xff;  //低位
            //printf("%d %d\n", in[t][j-1], in[t][j]);

            i = i + 3;
            j++;
        } else if (sentence[i] < 0xfffffff8 ) { //4位
            //print_u(sentence, i, 4);
            i = i + 4;
            printf("4字节的utf8编码，看看怎么回事？\n");
            exit(0);
        } else if (sentence[i] < 0xfffffffc ) { //5位
            //print_u(sentence, i, 5);
            i = i + 5;
            printf("5字节的utf8编码，看看怎么回事？\n");
            exit(0);
        } else {    //6位
            //print_u(sentence, i, 6);
            i = i + 6;
            printf("6字节的utf8编码，看看怎么回事？\n");
            exit(0);
        }
        k++;    //输出向量游标增1
    }
}

