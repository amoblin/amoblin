#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>

#include <math.h>
#include "config.h"
#include "utils.h"
#include "matrix.h"

int usage(char *argv[])
{
    printf("usage: %s [matrix file] [weight file]\n", argv[0]);
    return 0;
}

int train_bp(Matrix* w1, Matrix* w2, double (*in)[IN_NODES], double (*out)[OUT_NODES], FILE* matrix_fp, FILE* plot_fp, int data_size) {
    /* 初始化矩阵 \*/
    /* n1 = w1 . a0 \*/
    double *n1 = (double *) malloc( sizeof(double) * w1->m);

    /* a1 = f(n1) \*/
    double *a1 = (double *)malloc( sizeof(double) * w1->m);

    /* n2 = w2 . a1 \*/
    double *n2 = (double *)malloc( sizeof(double) * w2->m);

    /* a2 = f(n2) \*/
    double *a2 = (double *)malloc( sizeof(double) * w2->m);

    /* diff2 = out - a2 \*/
    assert( w2->m == OUT_NODES);
    double *diff2 = malloc( sizeof(double) * w2->m);

    /* h2 = _f(n2) = _h(a2) \*/
    double* h2 = malloc( sizeof(double) * w2->m);

    /* h2 = 0 - 2 . h2 \*/
    double* zero = malloc( sizeof(double) * w2->m);
    memset(zero, 0, sizeof(double) * w2->m);

    /* s2 = -2 . h2 x diff2 \*/
    double* s2 = malloc( sizeof(double) * w2->m);

    /* diff1 = w2^T . s2 \*/
    double* diff1 = malloc( sizeof(double) * w2->n);

    /* h1 = _f(n1) = _h(a1) \*/
    double* h1 = malloc( sizeof(double) * w1->m);

    /* s1 = h1 x diff1 \*/
    assert(w2->n == w1->m);
    double* s1 = malloc( sizeof(double) * w1->m);

    /* delta1 = s1 . a0^T \*/
    Matrix* delta1 = matrix_init(w1->m, w1->n);

    /* delta2 = s2 . a1^T \*/
    Matrix* delta2 = matrix_init(w2->m, w2->n);

    /* 备份权值矩阵以便回退 \*/
    Matrix* w1_old = matrix_init(w1->m, w1->n);
    Matrix* w2_old = matrix_init(w2->m, w2->n);

    /* 计时器 */
    int time_s = time((time_t*)NULL);

    /* 学习率 */
    double alpha = LEARN_RATE;

    double old_e = 9999;
    double e = PRECISION + 1;
    int n;
    syslog(LOG_DEBUG, "trainning times: %d\n", LOOP_MAX);
    for (n = 0; e > PRECISION && n < LOOP_MAX; n++) {
        e = 0;
        int i;
        for (i = 0; i < data_size; i++) {

            /* 输入正传 */
            matrix_dot_multiply(w1, in[i], n1, NORMAL);
            matrix_fnet(n1, a1, w1->m);

            matrix_dot_multiply(w2, a1, n2, NORMAL);
            matrix_fnet(n2, a2, w2->m);

            /* 误差反传 */
            matrix_fnet_dot(a2, h2, w2->m);
            vector_plus(zero, h2, h2, w2->m, -2);
            vector_plus(out[i], a2, diff2, w2->m, -1);
            matrix_multiply(h2, diff2, s2, w2->m);

            matrix_fnet_dot(a1, h1, w1->m);
            matrix_dot_multiply(w2, s2, diff1, REVERSE);
            matrix_multiply(h1, diff1, s1, w1->m);

            /* 计算输出误差 */
            double e_once;
            vector_norm(a2, out[i], w2->m, &e_once);
            e += e_once;

            /* 更新权值 */
            vector_dot_multiply(s1, in[i], delta1);
            matrix_plus(w1, delta1, w1, alpha * -1);

            vector_dot_multiply(s2, a1, delta2);
            matrix_plus(w2, delta2, w2, alpha * -1);
        }
        if (e < old_e) {
            matrix_copy(w1, w1_old);
            matrix_copy(w2, w2_old);
            old_e = e;
        } else {
            //alpha = 0.99 * alpha;
            //syslog(LOG_INFO, "alpha change: %2.1f", alpha);
            matrix_copy(w1_old, w1);
            matrix_copy(w2_old, w2);
        }

        /* 写入日志 */
        if (0 == (n % LOG_DEN)) {
            time_t time_e = time(NULL);
            struct tm *timeinfo;
            timeinfo = localtime(&time_e);
            int seconds = (int)difftime(time_e, time_s);
            int mins = seconds % 3600;
            int secs = mins % 60;
            syslog(LOG_DEBUG, "%02d:%02d:%02d %02dh%02dm%02ds %dw %2.1f %f\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, seconds/3600, mins/60, secs, n/LOG_DEN, alpha, e);
            /* 保存权值矩阵 */
            fseek(matrix_fp, 0, SEEK_SET);
            int i;
            fwrite(w1->matrix, sizeof(double), w1->m * w1->n, matrix_fp);
            fwrite(w2->matrix, sizeof(double), w2->m * w2->n, matrix_fp);
            fflush(matrix_fp);
        }

        /* 保存图像数据 */
        if( n % PLOT_DEN == 0) {
            fprintf(plot_fp, "%d %2.1f %2.1f\n", n/PLOT_DEN, e, alpha);
        }
    }
    /* 释放矩阵内存 */
    free(n1);
    free(a1);
    free(n2);
    free(a2);
    free(diff2);
    free(h2);
    free(zero);
    free(s2);
    free(diff1);
    free(h1);
    free(s1);
    matrix_free(delta1);
    matrix_free(delta2);
    matrix_free(w1_old);
    matrix_free(w2_old);
    return 0;
}

int main(int argc, char* argv[])
{
    char in_file[128];
    char out_file[128];
    char plot_file[128];
    FILE *matrix_fp = NULL;
    FILE *plot_fp = NULL;

    /* 记录日志 */
    int logfd = open( "nn.log", O_RDWR | O_CREAT | O_APPEND, 0644 );
    close(STDERR_FILENO);
    dup2(logfd, STDERR_FILENO);
    close(logfd);
    openlog(NULL, LOG_PERROR, LOG_DAEMON);

    /* 输入参数分析 */
    int ch;
    int flag=0;
    do {
        ch = getopt(argc, argv, "i:o:g:h");
        switch(ch) {
            case 'i':
                strncpy(in_file, optarg, sizeof(in_file) -1 );
                flag++;
                break;
            case 'o':
                strncpy(out_file, optarg, sizeof(out_file) -1 );
                flag++;
                break;
            case 'g':
                strncpy(plot_file, optarg, sizeof(plot_file) -1 );
                flag++;
                break;
            case 'h':
                usage(argv);
                break;
            case '?':
            default:
                break;
        }
    } while( -1 != ch);
    if(3 > flag) {
        usage(argv);
        return 0;
    }

    /* 读取样本数据 */
    matrix_fp = fopen(in_file, "rb");
    if (matrix_fp == NULL) {
        printf("Error! File %s does not exist.\n", in_file);
        exit(0);
    }
    /* 获取数据量 */
    int data_size;
    fread(&data_size, sizeof(int), 1, matrix_fp);

    /* 输入输出矩阵分配内存 */
    double in[data_size][IN_NODES];
    double out[data_size][OUT_NODES];

    /* 读取输入输出矩阵 */
    char char_in[data_size][IN_NODES];
    char char_out[data_size][OUT_NODES];
    int i,j;
    fread(char_in, sizeof(char), data_size * IN_NODES, matrix_fp);
    fread(char_out, sizeof(char), data_size * OUT_NODES, matrix_fp);
    fclose(matrix_fp);

    for( i=0; i<data_size; i++) {
        for( j=0; j<IN_NODES; j++) {
            in[i][j] = char_in[i][j];
        }
        for( j=0; j<OUT_NODES; j++) {
            out[i][j] = char_out[i][j] ? 0.9 : 0.1;
        }
    }

   /* 初始化隐含层权值矩阵 */
    Matrix *w1 = matrix_init(HIDDEN_NODES, IN_NODES);

   /* 初始化输出层权值矩阵 */
    Matrix *w2 = matrix_init(OUT_NODES, HIDDEN_NODES);

    matrix_fp = NULL;
    matrix_fp = fopen(out_file, "rb+");
    if (matrix_fp == NULL) { //不存在，使用随机数初始化
        /* 初始化权值矩阵 */
        syslog(LOG_INFO, "初始化矩阵");
        matrix_set_random(w1);
        matrix_set_random(w2);
        matrix_fp = fopen(out_file, "wb");
    } else {    //使用上一次的矩阵
        syslog(LOG_INFO, "使用上次矩阵");
        fread(w1->matrix, sizeof(double), w1->m * w1->n, matrix_fp);
        fread(w2->matrix, sizeof(double), w2->m * w2->n, matrix_fp);
    }

    /*
    matrix_print(w1);
    matrix_print(w2);
    */

    /* 保存数据点 */
    plot_fp = fopen(plot_file, "w");
    if (plot_fp == NULL) {
        syslog(LOG_ERR, "创建坐标数据文件失败");
        exit(0);
    }

    /* 训练 */
    syslog(LOG_INFO, "Start tranning...");
    train_bp(w1, w2, in, out, matrix_fp, plot_fp, data_size);
    fclose(matrix_fp);
    fclose(plot_fp);
    closelog();

    /* 释放内存 */
    matrix_free(w1);
    matrix_free(w2);

    return 0;
}
