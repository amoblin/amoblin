#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>
#include <stdarg.h>
#include <stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

int debug_level=5;

void d_printf(unsigned int level, const char * format, ...)
{
    if(level >= debug_level) {
        va_list ap;
        va_start(ap, format);
        vprintf(format, ap);
        va_end(ap);
    }
}

int print_u(char *ustring, int i, int n)
{
    int k;
    d_printf(1, "%d: ", i);
    for(k=0; k<n; k++) {
        printf("%c", ustring[i+k]);
    }
}

int get_utf8_bytes(char code)
{
    int length;
    if( code < 0xffffffc0) { //一位
        length = 1;
    } else if( code < 0xffffffe0 ) {  //2位
        length = 2;
    } else if ( code < 0xfffffff0 ) {  //3位
        length = 3;
    } else if ( code < 0xfffffff8 ) { //4位
        length = 4;
    } else if ( code < 0xfffffffc ) { //5位
        length = 5;
    } else {    //6位
        length = 6;
    }
    return length;
}

int utf82unicode(char* sentence, char* in, char* out)
{
    int i = 0;    //utf8编码串游标；
    int j = 1;  //输入向量游标；
    int k = 0;  //输出向量游标。
    while(i<strlen(sentence)) {
        int length =  get_utf8_bytes(sentence[i]);
        //print_u(sentence, i, length);
        unsigned short dest;//2字节
        switch(length) {
            case 1:
                if (sentence[i] == 32) { //空格
                    out[k-1] = 0; //分词点
                }
                break;
            case 3:
                dest = ( sentence[i] & 0x0F ) << 12;
                dest |= (sentence[i+1] & 0x3f) << 6;
                dest |= (sentence[i+2] & 0x3f);

                in[j] = dest >> 8;  //高位
                in[++j] = dest & 0xff;  //低位
                //syslog(LOG_DEBUG, "%2x %2x\t", in[j-1], in[j]);
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
    /* 保存本句汉字长度 */
    in[0] = k;

    d_printf(4, "Unicode向量:");
    int s;
    for (s = 1; s < 2 * k + 1; s++) {
        d_printf(4, "%x ",(unsigned char)in[s]);
    }
    d_printf(4, "\n输出向量:");
    for(s=0; s<k; s++) {
        d_printf(4, "%d ",out[s]);
    }
    d_printf(4, "\n");
}

int split4short(char* binary_in, char* tmp_out, 
        char in[][IN_NODES ], char out[][OUT_NODES], int *n) {
    int length = binary_in[0];
    int stop_point = length - OUT_NODES + 1;
    int i;
    char* data_begin = binary_in + 1;
    /* 忽略小于OUT_NODES个汉字的句子 */
    for (i = 0; i < stop_point; i++) {
        int j;
        memcpy(in[*n], data_begin, IN_NODES);
        memcpy(out[*n], tmp_out + i, OUT_NODES);
        (*n)++;        //向量数组游标增1

        /* 下移一个汉字的举例 */
        data_begin += 16;
    }

}

int unicode2binary(char* unicode_str, char *binary_str)
{
    int i;
    int j;
    int reset_num;
    int length = unicode_str[0] * 2;

    binary_str[0] = unicode_str[0];

    for (i = 0; i < length; i++) {
        reset_num = 128;
        d_printf(4, "0%03o: ",(unsigned char) unicode_str[i+1]);
        for(j=1; j<9; j++) {
            binary_str[8*i+j] = (unicode_str[i+1] & reset_num) >> (8-j) ;
            reset_num >>= 1;
            d_printf(4, "%d", binary_str[8*i+j]);
        }
        d_printf(4, "\n");
    }
}

int get_sub_num(char *sentence) {
    int i=0;
    int sen_len = strlen(sentence);
    int j;
    for(j=0; j< sen_len;j++) {
        /* 标点符号 */
        if ((unsigned char)sentence[j] < 128) {
            i++;
        }
    }
    int sub_num = (sen_len - i)/3 - OUT_NODES;
    sub_num = (sub_num > 0 ) ? sub_num + 1 : 1;
    return sub_num;
}


int get_subsentences_num(FILE *fp)
{
    char buffer[UTF8_LEN];
    int data_size=0;
    while( fgets(buffer, sizeof(buffer), fp) != NULL) {
        data_size += get_sub_num(buffer);
    }
    fseek(fp, 0, SEEK_SET);
    return data_size;
}

