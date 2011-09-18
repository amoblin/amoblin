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
    int data_size = get_data_size(fp);
    /* 保存规格化数据 */
    unsigned char tmp_short[data_size][OUT_NODES * 3];
    int n = 0;  //向量数组游标
    while(fgets(sentence, UTF8_LEN, fp) != NULL)
    {
        d_printf(5, "%s", sentence);
        /* 保存转换为unicode码的句子 */
        unsigned char tmp_in[UNI_LEN] = {0};
        /* 保存转换为二进制码的句子 */
        unsigned char binary_in[BIN_LEN] = {0};
        /* 保存输出值 */
        unsigned char tmp_out[SEN_LEN];//默认为0，不需清零先。
        int i;
        for(i=0; i< SEN_LEN; i++) {
            tmp_out[i] = 1;
        }

        utf82unicode(sentence, tmp_in, tmp_out);
        unicode4short(tmp_in, tmp_out, tmp_short, &n);
        //unicode2binary(tmp_in, binary_in);

    }
    fclose(fp);

    double in[data_size][IN_NODES];
    double out[data_size][OUT_NODES];
    int i,j;
    for (i = 0; i < data_size; i++) {
        for (j = 0; j < IN_NODES; j++) {
            in[i][j] = tmp_short[i][j];
        }
        for (j = 0; j < OUT_NODES; j++) {
            out[i][j] = tmp_short[i][IN_NODES+j] ? 0.9:0.1;
        }
    }

    /* 保存矩阵 */
    FILE *vector_p = NULL;
    vector_p = fopen(out_file, "wb");

    fwrite(&data_size, sizeof(int), 1, vector_p);
    fwrite(in, sizeof(double), IN_NODES * data_size, vector_p);
    fwrite(out, sizeof(double), OUT_NODES * data_size, vector_p);
    fclose(vector_p);

    return 0;
}
