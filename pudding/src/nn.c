#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>

#include "nn.h"

int usage(char *argv[])
{
    printf("usage: %s [matrix file] [weight file]\n", argv[0]);
    return 0;
}

int train_bp(Matrix* w1, Matrix* w2, Matrix* in, Matrix* out, FILE* vector_p, FILE* fp) {
    double alpha = LEARN_RATE;  //学习率
    double delta_hidden[HIDDEN_NODES], delta_out[OUT_NODES];    //修改量矩阵
    double O1[HIDDEN_NODES], O2[OUT_NODES]; //隐层和输出层输出量
    int i, j, k, n;
    double sum;

    double e = PRECISION + 1;


    /* 初始化矩阵 */
    Matrix* n1;
    matrix_init(in->m, w1->n, &n1);

    Matrix* a1;
    matrix_init(n1->m, n1->n, &a1);

    Matrix* n2;
    matrix_init(a1->m, w2->n, &n2);

    Matrix* a2;
    matrix_init(n2->m, n2->n, &a2);

    Matrix* diff2;
    matrix_init(a2->m, a2->n, &diff2);

    Matrix* h2;
    matrix_init(a2->m, a2->n, &h2);

    Matrix *s2;
    matrix_init(a2->m, a2->n, &s2);


    Matrix* diff1;
    matrix_init(w2->n, a2->n, &diff1);

    Matrix* h1;
    matrix_init(a1->m, a1->n, &h1);

    Matrix *s1;
    matrix_init(a1->m, a1->n, &s1);

    /* 动态更新权值 */
    double old_e;
    double old_v[IN_NODES][HIDDEN_NODES];
    double old_w[HIDDEN_NODES][OUT_NODES];

    /* 计时器 */
    int time_s = time((time_t*)NULL);

    old_e = 9999;
    printf("LOOP_MAX: %d\n", LOOP_MAX);
    for (n = 0; e > PRECISION && n < LOOP_MAX; n++) {
        e = 0;

        /* 输入正传 */
        matrix_dot_multiply(in, w1, n1, NORMAL);
        matrix_fnet(n1, a1);

        matrix_dot_multiply(a1, w2, n2, NORMAL);
        matrix_fnet(n2, a2);

        /* 误差反传 */
        matrix_plus(out, a2, diff2, -1);
        matrix_multiply(h2, diff2, s2);

        matrix_dot_multiply(w2, s2, diff1, REVERSE1);
        matrix_multiply(h1, diff1, s1);

        /* 更新权值 */
        matrix_dot_multiply(s1, in, delta1, REVERSE2);
        matrix_plus(w1, delta1, w1, alpha * -1);

        matrix_dot_multiply(s2, a1, delta2, REVERSE2);
        matrix_plus(w2, delta2, w2, alpha * -1);

        /* 计算输出误差 */
        matrix_fanshu(a2, out, &e);

        d_printf(1, "e:%f\n",e);
        //d_printf(1, "old e:%f\n",old_e);
        //double temp_e = e - old_e;
        //d_printf(1, "%f\n", temp_e);
        if (e > old_e) {
            d_printf(3, "e:%f\n",e);
            d_printf(3, "old_e:%f\n",old_e);
        }
        if (e <= old_e+0.5) {
            /* 进行权值更新 */
            old_e = e;
            memcpy(old_v, v, sizeof(double) * IN_NODES * HIDDEN_NODES);
            memcpy(old_w, w, sizeof(double) * HIDDEN_NODES * OUT_NODES);
        } else {
            /* 取消权值更新 */
            memcpy(v, old_v, sizeof(double) * IN_NODES * HIDDEN_NODES);
            memcpy(w, old_w, sizeof(double) * HIDDEN_NODES * OUT_NODES);
            alpha = 0.99 * alpha;
            d_printf(3, "alpha changed:%f\n", alpha);
        }

        if (0 == (n % LOG_DEN)) {
            /* 写入日志 */
            time_t time_e = time(NULL);
            struct tm *timeinfo;
            timeinfo = localtime(&time_e);
            int seconds = (int)difftime(time_e, time_s);
            int mins = seconds % 3600;
            int secs = mins % 60;
            syslog(LOG_USER|LOG_DEBUG, "%02d:%02d:%02d %02dh%02dm%02ds %d %f %f\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, seconds/3600, mins/60, secs, n, alpha, e);
            /* 保存权值矩阵 */
            fseek(vector_p, 0, SEEK_SET);
            fwrite(v, HIDDEN_NODES * sizeof(double), IN_NODES, vector_p);
            fwrite(w, OUT_NODES * sizeof(double), HIDDEN_NODES, vector_p);
            fflush(vector_p);
        }

        /* 保存图像数据 */
        if( n % PLOT_DEN== 0) {
            fprintf(fp, "%d %f %f\n", n/PLOT_DEN, e, alpha);
        }
    }

    fclose(fp);
    fclose(vector_p);

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
    matrix_init(data_size, IN_NODES, &in, UNSIGNED_CHAR);
    //unsigned char **in = (unsigned char**) malloc(sizeof(unsigned char*) * data_size);
    Matrix *out;
    matrix_init(data_size, OUT_NODES, &out, DOUBLE);
    //double **out = (double **) malloc(sizeof(double *) * data_size);

    /*
    int i,j;
    for(i=0;i<data_size;i++) {
        in[i] = NULL;
        in[i] = (unsigned char*) malloc(sizeof(unsigned char) * IN_NODES);
        if(NULL == in[i]) {
            printf("malloc failed.\n");
            exit(0);
        }
        out[i] = NULL;
        out[i] = (double *) malloc(sizeof(double) * OUT_NODES);
        if(NULL == out[i]) {
            printf("malloc failed.\n");
            exit(0);
        }
    }
    */

    /* 读入输入输出矩阵 */
    int i,j;
    for(i=0;i<data_size;i++) {
        fread(in->matrix.cm[i], sizeof(unsigned char), IN_NODES, vector_p);
        fread(out->matrix.dm[i], sizeof(double), OUT_NODES, vector_p);
    }
    fclose(vector_p);

    d_printf(1, "matrix in:\n");
    for(i=0; i < data_size; i++) {
        for(j=0; j < IN_NODES ; j++) {
            d_printf(1, "%d ", in->matrix.cm[i][j]);
        }
        d_printf(1, "\n");
    }

   /* 初始化隐含层权值矩阵 */
    Matrix *v;
    matrix_init(IN_NODES, HIDDEN_NODES, &v, DOUBLE);

   /* 初始化输出层权值矩阵 */
    Matrix *w;
    matrix_init(HIDDEN_NODES, OUT_NODES, &w, DOUBLE);

    vector_p = NULL;
    vector_p = fopen(out_file, "rb+");
    if (NULL == vector_p) { //不存在，使用随机数初始化
        /* 初始化权值矩阵 */
        syslog(LOG_INFO, "初始化矩阵");
        matrix_set_random(v);
        matrix_set_random(w);
        vector_p = fopen(out_file, "wb");
    } else {    //使用上一次的矩阵
        syslog(LOG_INFO, "使用上次矩阵");
        fread(v->matrix.dm, HIDDEN_NODES * sizeof(double), IN_NODES, vector_p);
        fread(w->matrix.dm, OUT_NODES * sizeof(double), HIDDEN_NODES, vector_p);
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
    train_bp(v, w, in, out, data_size, vector_p, fp);             //训练bp神经网络

    /* 释放内存 */
    matrix_free(in);
    matrix_free(out);
    matrix_free(v);
    matrix_free(w);
    closelog();
    return 0;
}
