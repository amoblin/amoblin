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
    char sentence[UTF8_LEN];  //语句长度最大值：18
    int data_size = get_data_size(fp);
    unsigned char **in = (unsigned char **) malloc(sizeof(unsigned char*) * data_size);
    //unsigned char in[DATA_SIZE][IN_NODES];  //无符号字符型数组，元素范围0～255.两个数字代表一个汉字。
    double **out = (double **) malloc(sizeof(double *) * data_size);//输出向量，0.9代表连续，0.1代表分词点
    int i;
    for(i=0;i<data_size;i++)
    {
        in[i] = NULL;
        in[i] = (unsigned char *) malloc(sizeof(unsigned char) * IN_NODES);
        if(NULL == in[i]) {
            printf("malloc failed.\n");
            exit(0);
        }
        //memset(in[i], 0, sizeof(unsigned char) * IN_NODES);
        out[i] = NULL;
        out[i] = (double*) malloc(sizeof(double) * OUT_NODES);
        if(NULL == out[i]) {
            printf("malloc failed.\n");
            exit(0);
        }
    }
    int t = 0;  //向量数组游标
    while(fgets(sentence, UTF8_LEN, fp) != NULL)
    {
        d_printf(0, "%s", sentence);
        /* 保存转换为unicode码的句子 */
        unsigned char tmp_in[UNI_LEN] = {0};
        /* 保存转换为二进制码的句子 */
        unsigned char binary_in[BIN_LEN] = {0};
        /* 保存输出值 */
        double tmp_out[SEN_LEN];//默认为0，不需清零先。
        for(i=0; i< SEN_LEN; i++) {
            tmp_out[i] = 0.9;
        }
        utf82unicode(sentence, tmp_in, tmp_out);
        unicode2binary(tmp_in, binary_in);
        int length = strlen(tmp_in)/2;//该句汉字数。
        for(i=0;i<length-3;i++) {
            memcpy(in[t],binary_in + i*16, sizeof(unsigned char) * IN_NODES);
            int j;
            for(j=0; j< IN_NODES; j++) {
                d_printf(1, "%d ", in[t][j]);
            }
            d_printf(1, "\n");
            memcpy(out[t], tmp_out + i, sizeof(double) * OUT_NODES);
            for(j=0; j< OUT_NODES; j++) {
                //syslog(LOG_DEBUG, "%f ", out[t][j]);
            }
            t++;        //向量数组游标增1
        }
    }
    fclose(fp);

    /* 保存矩阵 */
    FILE *vector_p = NULL;
    vector_p = fopen(out_file, "wb");

    fwrite(&data_size, sizeof(int), 1, vector_p);
    for(i=0;i<data_size;i++) {
        fwrite(in[i], sizeof(unsigned char), IN_NODES, vector_p);
        fwrite(out[i], sizeof(double), OUT_NODES, vector_p);
    }
    fclose(vector_p);

    /* 内存释放 */
    for(i=0;i<data_size;i++)
    {
        free(in[i]);
        free(out[i]);
    }
    free(in);
    free(out);

    return 0;
}
