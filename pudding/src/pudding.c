#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "config.h"
#include "utils.h"
#include "matrix.h"

#define LEFT_B 0.4
#define RIGHT_B 0.6

int usage(char *argv[])
{
    printf("usage: %s [network matrix] [sentence]\n", argv[0]);
}

void use_nn(Matrix *w1, Matrix *w2, double (*in)[IN_NODES], double (*out)[OUT_NODES], int num) {

    double *n1 = malloc( sizeof(double) * w1->m);
    /* a1 = f(n1) \*/
    double *a1 = (double *)malloc( sizeof(double) * w1->m);
    /* n2 = w2 . a1 \*/
    double *n2 = (double *)malloc( sizeof(double) * w2->m);

    int i;
    for(i=0; i<num; i++) {
        int j;
        matrix_dot_multiply(w1, in[i], n1, NORMAL);
        matrix_fnet(n1, a1, w1->m);

        matrix_dot_multiply(w2, a1, n2, NORMAL);
        matrix_fnet(n2, out[i], w2->m);
    }
}

int main(int argc, char *argv[])
{
    /* 日志输出 */
    int logfd = open("pudding.log", O_RDWR|O_CREAT|O_APPEND, 0644);
    if(-1 == logfd) {
        return -1;
    }
    close(STDERR_FILENO);
    /* 重定向到logfd */
    dup2(logfd, STDERR_FILENO);
    close(logfd);
    openlog(NULL, LOG_PERROR, LOG_DAEMON);

    /* 参数处理 */
    unsigned char sentence[UTF8_LEN];
    char weight_file[128];
    char ch;
    int flag = 0;
    do {
        ch = getopt(argc, argv, "l:s:h");
        switch(ch) {
            case 'l':
                strncpy(weight_file, optarg, sizeof(weight_file) - 1);
                syslog(LOG_INFO, "load weight matrix: %s", weight_file);
                flag++;
                break;
            case 's':
                strncpy(sentence, optarg, sizeof(sentence) - 1);
                syslog(LOG_INFO, "load sentence: %s", sentence);
                flag++;
                break;
            case 'h':
                usage(argv);
                break;
            default:
                break;
        }
    } while(-1 != ch);
    if( 2 > flag) {
        usage(argv);
        return 0;
    }

   /* 初始化各层权值矩阵 */
    Matrix *w1 = matrix_init(HIDDEN_NODES, IN_NODES);
    Matrix *w2 = matrix_init(OUT_NODES, HIDDEN_NODES);

    FILE *matrix_fp = NULL;
    matrix_fp = fopen(weight_file, "rb");
    if (NULL == matrix_fp) {
        printf("Error! %s does not exist.\n", weight_file);
        exit(0);
    }
    fread(w1->matrix, sizeof(double), w1->m * w1->n, matrix_fp);
    fread(w2->matrix, sizeof(double), w2->m * w2->n, matrix_fp);
    fclose(matrix_fp);

    /* 整句utf8转unicode */
    char tmp_in[UNI_LEN];
    char tmp_out[SEN_LEN];
    char binary_in[BIN_LEN];

    utf82unicode(sentence, tmp_in, tmp_out);
    unicode2binary(tmp_in, binary_in);

    int length = tmp_in[0];

    /* 子句集 */
    int subsen_num;
    subsen_num = (length > OUT_NODES) ? length - OUT_NODES + 1 : 1;

    double in[subsen_num][IN_NODES];
    double out[subsen_num][OUT_NODES];

    char char_in[subsen_num][IN_NODES];
    char char_out[subsen_num][OUT_NODES];

    int n=0;
    split4short(binary_in, tmp_out, char_in, char_out, &n);

    int i,j;
    for(i=0; i< subsen_num; i++) {
        for(j=0; j< IN_NODES; j++) {
            in[i][j] = char_in[i][j];
        }
        for(j=0; j< OUT_NODES; j++) {
            out[i][j] = char_out[i][j];
        }
    }

    use_nn(w1, w2, in, out, subsen_num);

    for(i=0; i<subsen_num; i++) {
        for(j=0; j<OUT_NODES; j++) {
            d_printf(1, "%2.1f ", out[i][j]);
        }
        d_printf(1, "\n");
    }

    /* 综合子句结果 */
    double result[length];

    /* 设定阈值 */
    for(i=0; i< length; i++) {
        result[i] = 0;

        j = max(0, i - OUT_NODES+1);
        int flag = min(i+1, subsen_num);
        int nums = flag - j;

        for(; j < flag; j++) {
            result[i] += out[j][i-j];
        }
        result[i] = result[i] / nums;

        syslog(LOG_INFO, "%2.1f ", result[i]);

        if( result[i] < LEFT_B) {
            d_printf(2,"%2.1f", result[i]);
            result[i] = 0;
        } else if( result[i] > RIGHT_B) {
            d_printf(2,"%2.1f", result[i]);
            result[i] = 1;
        } else {
            syslog(LOG_ERR, "can not split: %2.1f.\n", result[i]);
        }
    }

    i = 0;
    j = 0;
    while( i< strlen(sentence)) {
        int len = get_utf8_bytes(sentence[i]);
        print_u(sentence, i, len);
        if( result[j] == 0 ) {
            printf("/");
        }
        j++;
        i = i + len;
    }
    printf("\n");

    return 0;
}
