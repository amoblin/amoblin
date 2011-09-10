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

int train_bp(Matrix* v, Matrix* w, Matrix* in, Matrix* out, FILE* vector_p, FILE* fp) {
    double alpha = LEARN_RATE;  //学习率
    double delta_hidden[HIDDEN_NODES], delta_out[OUT_NODES];    //修改量矩阵
    double O1[HIDDEN_NODES], O2[OUT_NODES]; //隐层和输出层输出量
    int i, j, k, n;
    double sum;

    double e = PRECISION + 1;


    Matrix* a1;
    matrix_init(in->m, v->n, &a1, DOUBLE);

    Matrix* f1;
    matrix_init(a1->m, a1->n, &f1, DOUBLE);

    Matrix* a2;
    matrix_init(f1->m, w->n, &a2, DOUBLE);

    Matrix* f2;
    matrix_init(a2->m, a2->n, &f2, DOUBLE);

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
        matrix_dot_multiply(in, v, a1);
        matrix_fnet(a1, f1);

        matrix_dot_multiply(f1, w, a2);
        matrix_fnet(a2, f2);
        for (i=0; i < in->m; i++) { 

            /* 计算输出层的权修改量 */
            for (j = 0; j < OUT_NODES; j++) {
                delta_out[j] = -2 * O2[j] * (1 - O2[j]) * (out[i][j] - O2[j]);
            }

            /* 计算隐层权修改量 */
            for (k = 0; k < HIDDEN_NODES; k++) {
                sum = 0;
                for (j = 0; j < OUT_NODES; j++) {
                    sum += w[k][j] * delta_out[j];
                }
                delta_hidden[j] = -2 * O1[j] * (1 - O1[j]) * sum;
            }

            /* 调整隐含层权值矩阵 */
            for (j = 0; j < IN_NODES; j++) {
                for (k = 0; k < HIDDEN_NODES; k++) {
                    v[j][k] -= alpha * in[i][j] * delta_hidden[k]; 
                }
            }
            /* 调整输出层权值矩阵 */
            for (j = 0; j < HIDDEN_NODES; j++) {
                for (k = 0; k < OUT_NODES; k++) {
                    w[j][k] -= alpha * O1[j] * delta_out[k]; 
                }
            }

            /* 计算输出误差 */
            for (j = 0; j < OUT_NODES ; j++) {
                //printf("%f \n", (out[i][j] - O2[j]) * (out[i][j] - O2[j]));
                e += (out[i][j] - O2[j]) * (out[i][j] - O2[j]);
            }
        }
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
