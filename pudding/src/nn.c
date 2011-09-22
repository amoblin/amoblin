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

int train_bp(Matrix* w1, Matrix* w2, Matrix* in, Matrix* out, FILE* vector_p, FILE* fp) {
    /* 初始化矩阵 \*/
    /* n1 = w1 . a0 \*/
    assert(w1->n == in->n);
    double *n1 = malloc( sizeof(double) * w1->m);

    /* a1 = f(n1) \*/
    double *a1 = malloc( sizeof(double) * w1->m);

    /* n2 = w2 . a1 \*/
    double *n2 = malloc( sizeof(double) * w2->m);

    /* a2 = f(n2) \*/
    double *a2 = malloc( sizeof(double) * w2->m);

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
    Matrix* delta1;
    matrix_init(w1->m, w1->n, &delta1);

    /* delta2 = s2 . a1^T \*/
    Matrix* delta2;
    matrix_init(w2->m, w2->n, &delta2);

    /* 备份权值矩阵以便回退 \*/
    Matrix* w1_old;
    matrix_init(w1->m, w1->n, &w1_old);
    Matrix* w2_old;
    matrix_init(w2->m, w2->n, &w2_old);

    /* 计时器 */
    int time_s = time((time_t*)NULL);

    /* 学习率 */
    double alpha = LEARN_RATE;

    double old_e = 9999;
    double e = PRECISION + 1;
    int n;
    printf("LOOP_MAX: %d\n", LOOP_MAX);
    for (n = 0; e > PRECISION && n < LOOP_MAX; n++) {
        e = 0;
        int i;
        for (i = 0; i < in->m; i++) {

            /* 输入正传 */
            matrix_dot_multiply(w1, in->matrix[i], n1, NORMAL);
            matrix_fnet(n1, a1, w1->m);
            d_printf(3, "a1向量：");
            vector_printf(a1, w1->m, 3);

            matrix_dot_multiply(w2, a1, n2, NORMAL);
            matrix_fnet(n2, a2, w2->m);
            d_printf(3, "a2向量：");
            vector_printf(a2, w2->m, 3);

            /* 误差反传 */
            matrix_fnet_dot(a2, h2, w2->m);
            vector_plus(zero, h2, h2, w2->m, -2);
            vector_plus(out->matrix[i], a2, diff2, w2->m, -1);
            matrix_multiply(h2, diff2, s2, w2->m);

            matrix_fnet_dot(a1, h1, w1->m);
            matrix_dot_multiply(w2, s2, diff1, REVERSE);
            matrix_multiply(h1, diff1, s1, w1->m);

            /* 计算输出误差 */
            double e_once;
            matrix_fanshu(a2, out->matrix[i], w2->m, &e_once);
            e += e_once;
            d_printf(4, "e:%f\n",e_once);

            /* 更新权值 */
            vector_dot_multiply(s1, in->matrix[i], delta1);
            matrix_plus(w1, delta1, w1, alpha * -1);

            vector_dot_multiply(s2, a1, delta2);
            matrix_plus(w2, delta2, w2, alpha * -1);
        }
        d_printf(5, "e:%f\n",e);
        d_printf(5, "old e:%f\n",old_e);
        if (e < old_e) {
            matrix_copy(w1, w1_old);
            matrix_copy(w2, w2_old);
            old_e = e;
        } else {
            //alpha = 0.99 * alpha;
            d_printf(5, "alpha changed:%f\n", alpha);
            //matrix_copy(w1_old, w1);
            //matrix_copy(w2_old, w2);
        }

        /* 写入日志 */
        if (0 == (n % LOG_DEN)) {
            time_t time_e = time(NULL);
            struct tm *timeinfo;
            timeinfo = localtime(&time_e);
            int seconds = (int)difftime(time_e, time_s);
            int mins = seconds % 3600;
            int secs = mins % 60;
            syslog(LOG_DEBUG, "%02d:%02d:%02d %02dh%02dm%02ds %dw %f %f\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, seconds/3600, mins/60, secs, n/LOG_DEN, alpha, e);
            /* 保存权值矩阵 */
            fseek(vector_p, 0, SEEK_SET);
            int i;
            for( i= 0; i< w1->m; i++) {
                fwrite(w1->matrix[i], sizeof(double), w1->n, vector_p);
            }
            for( i= 0; i< w2->m; i++) {
                fwrite(w2->matrix[i], sizeof(double), w2->n, vector_p);
            }
            fflush(vector_p);
        }

        /* 保存图像数据 */
        if( n % PLOT_DEN== 0) {
            fprintf(fp, "%d %f %f\n", n/PLOT_DEN, e, alpha);
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
    char xy_file[128];
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
                strncpy(xy_file, optarg, sizeof(xy_file) -1 );
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
    FILE *vector_p = NULL;
    vector_p = fopen(in_file, "rb");
    if (vector_p == NULL) {
        printf("Error! File %s does not exist.\n", in_file);
        exit(0);
    }
    /* 获取数据量 */
    int data_size;
    fread(&data_size, sizeof(int), 1, vector_p);
    /* 输入输出矩阵分配内存 */
    Matrix *in;
    matrix_init(data_size, IN_NODES, &in);
    Matrix *out;
    matrix_init(data_size, OUT_NODES, &out);

    /* 读取输入输出矩阵 */
    int i,j;
    for(i=0;i<data_size;i++) {
        fread(in->matrix[i], sizeof(double), IN_NODES, vector_p);
    }
    for(i=0;i<data_size;i++) {
        fread(out->matrix[i], sizeof(double), OUT_NODES, vector_p);
    }
    fclose(vector_p);


   /* 初始化隐含层权值矩阵 */
    Matrix *w1;
    matrix_init(HIDDEN_NODES, IN_NODES, &w1);

   /* 初始化输出层权值矩阵 */
    Matrix *w2;
    matrix_init(OUT_NODES, HIDDEN_NODES, &w2);

    vector_p = NULL;
    vector_p = fopen(out_file, "rb+");
    if (NULL == vector_p) { //不存在，使用随机数初始化
        /* 初始化权值矩阵 */
        syslog(LOG_INFO, "初始化矩阵");
        matrix_set_random(w1);
        matrix_set_random(w2);
        vector_p = fopen(out_file, "wb");
    } else {    //使用上一次的矩阵
        syslog(LOG_INFO, "使用上次矩阵");
        for(i= 0; i< w1->m; i++) {
            fread(w1->matrix[i], sizeof(double), w1->n, vector_p);
        }
        for(i= 0; i< w2->m; i++) {
            fread(w2->matrix[i], sizeof(double), w2->n, vector_p);
        }
    }

    /* 保存数据点 */
    FILE *fp = NULL;
    fp = fopen(xy_file, "w");
    if (NULL == fp) {
        syslog(LOG_ERR, "创建坐标数据文件失败");
        exit(0);
    }

    /* 训练 */
    printf("开始网络训练\n");
    train_bp(w1, w2, in, out, vector_p, fp);             //训练bp神经网络
    fclose(vector_p);
    fclose(fp);

    /* 释放内存 */

    matrix_free(in);
    matrix_free(out);
    matrix_free(w1);
    matrix_free(w2);
    closelog();
    return 0;
}
