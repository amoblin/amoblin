#include <stdio.h>
#include "config.h"
#include "utils.h"

int usage(char *argv[])
{
    printf("usage: %s -i [sentence file] -o [matrix file]\n", argv[0]);
    return 0;
}

int main(int argc, char *argv[])
{
    /* 日志输出 */
    int logfd = open("convert.log", O_RDWR|O_CREAT|O_APPEND, 0644);
    if(-1 == logfd) {
        return -1;
    }
    close(STDERR_FILENO);
    dup2(STDOUT_FILENO, STDERR_FILENO);
    close(logfd);
    openlog(NULL, LOG_PERROR, LOG_DAEMON);
    //setlogmask(LOG_ERR);

    /* 输入参数处理 */
    int ch;
    char in_file[128];
    char out_file[128];
    int flag = 0;
    do{
        ch = getopt(argc, argv, "i:o:h");
        switch(ch) {
            case 'i':
                strncpy(in_file, optarg, sizeof(in_file) - 1);
                syslog(LOG_DEBUG, "input file:%s", optarg);
                flag++;
                break;
            case 'o':
                strncpy(out_file, optarg, sizeof(out_file) - 1);
                syslog(LOG_DEBUG, "output file:%s", optarg);
                flag++;
                break;
            case 'h':
                usage(argv);
                break;
            case '?':
            default:
                break;
        }
    } while(-1 != ch);
    if(2 > flag) {
        usage(argv);
        return 0;
    }

    /* 读取输入 */
    FILE *fp = NULL;
    fp = fopen(in_file, "r");
    if(fp == NULL) {
        syslog(LOG_ERR, "file: %s does not exist, please check again.\n", argv[1]);
        return 0;
    }
    char sentence[UTF8_LEN];
    int data_size = get_subsentences_num(fp);

    /* 子句集*/
    char in[data_size][IN_NODES];
    char out[data_size][OUT_NODES];

    int n = 0;  //向量数组游标
    while(fgets(sentence, UTF8_LEN, fp) != NULL)
    {
        syslog(LOG_DEBUG, "处理句子：%s", sentence);
        /* 保存转换为unicode码的句子 */
        char tmp_in[UNI_LEN] = {0};
        /* 保存转换为二进制码的句子 */
        char binary_in[BIN_LEN] = {0};
        /* 保存输出值 */
        char tmp_out[SEN_LEN];//默认为0，不需清零先。
        int i;
        for(i=0; i< SEN_LEN; i++) {
            tmp_out[i] = 1;
        }

        /* utf8转unicode，提取切分信息 */
        utf82unicode(sentence, tmp_in, tmp_out);
        /* unicode转二进制 */
        unicode2binary(tmp_in, binary_in);
        /* 切分子句 */
        split4short(binary_in, tmp_out, in, out, &n);
    }
    fclose(fp);

    /* 保存矩阵 */
    FILE *vector_p = NULL;
    vector_p = fopen(out_file, "wb");

    fwrite(&data_size, sizeof(int), 1, vector_p);
    fwrite(in, sizeof(char), IN_NODES * data_size, vector_p);
    fwrite(out, sizeof(char), OUT_NODES * data_size, vector_p);
    fclose(vector_p);

    return 0;
}
