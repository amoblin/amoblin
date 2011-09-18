#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <syslog.h>
#include <stdarg.h>
#include <stdlib.h>

int debug_level=3;

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
        d_printf(1, "%c", ustring[i+k]);
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

int utf82unicode(char *sentence, unsigned char in[], unsigned char out[])
{
    int i = 0;    //utf8编码串游标；
    int j = 1;  //输入向量游标；
    int k = 0;  //输出向量游标。
    while(i<strlen(sentence)) {
        int length;
        get_utf8_bytes(sentence[i], &length);
        print_u(sentence, i, length);
        unsigned short dest;//2字节
        switch(length) {
            case 1:
                if (sentence[i] == '\n') {
                    in[0] = 2 * k;
                    d_printf(4, "Unicode向量:");
                    int s;
                    for (s = 1; s < 2 * k + 1; s++) {
                        d_printf(4, "%o ",in[s]);
                    }
                    d_printf(4, "\n输出向量:");
                    for(s=0; s<k; s++) {
                        d_printf(4, "%d ",out[s]);
                    }
                    d_printf(4, "\n");
                } else if (sentence[i] == 32) { //空格
                    out[k] = 0; //分词点
                }
                break;
            case 3:
                dest = ( sentence[i] & 0x0F ) << 12;
                dest |= (sentence[i+1] & 0x3f) << 6;
                dest |= (sentence[i+2] & 0x3f);

                in[j] = dest >> 8;  //高位
                in[++j] = dest & 0xff;  //低位
                d_printf(2, "%d %d\t", in[j-1], in[j]);
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
    d_printf(1, "\n");
}

int unicode4short(unsigned char* tmp_in, unsigned char* tmp_out, unsigned char short_str[][OUT_NODES * 3], int *n)
{
    int length = tmp_in[0] / 2;
    int stop_point = length - OUT_NODES + 1;
    int i;
    for (i = 0; i < stop_point; i++) {
        memcpy(short_str[*n], tmp_in + i*2, sizeof(unsigned char) * OUT_NODES * 2);
        memcpy(short_str[*n] + OUT_NODES * 2, tmp_out + i, sizeof(unsigned char) * OUT_NODES);
        int j;
        for (j = 0; j < OUT_NODES * 3; j++) {
            d_printf(3, "%d ", short_str[*n][j]);
        }
        d_printf(3, "\n");
        (*n)++;        //向量数组游标增1
    }
}

int unicode2binary(unsigned char* unicode_str, unsigned char *binary_str)
{
    int i;
    int j;
    int length = unicode_str[0];
    int reset_num;
    for (i = 0; i < length; i++) {
        reset_num = 128;
        d_printf(2, "0%o: ", unicode_str[i+1]);
        for(j=0; j<8; j++) {
            binary_str[8*i+j] = (unicode_str[i+1] & reset_num) >> (7-j) ;
            reset_num >>= 1;
            d_printf(2, "%d", binary_str[8*i+j]);
        }
        d_printf(2, "\n");
    }
}

int get_data_size(FILE *fp)
{
    char buffer[UTF8_LEN];
    int data_size=0;
    while( fgets(buffer, sizeof(buffer), fp) != NULL) {
        int i=0;
        int sen_len = strlen(buffer);
        int j;
        for(j=0; j< sen_len;j++) {
            if (buffer[j] == 32) {
                i++;
            }
        }
        /* 除去空格和行末回车 */
        int utf8_len = sen_len - i -1;

        data_size += utf8_len/3 - 3;
        //printf("%d\n",data_size);
    }
    fseek(fp, 0, SEEK_SET);
    return data_size;
}
