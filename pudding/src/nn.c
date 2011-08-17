#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <syslog.h>
#include <fcntl.h>
#include <unistd.h>

#include "nn.h"

int train_bp(double v[][HIDDEN_NODES], double w[][OUT_NODES], unsigned char **in, double **out, int data_size, FILE *vector_p, FILE *fp) {
    double alpha = LEARN_RATE;  //学习率
    double delta_hidden[HIDDEN_NODES], delta_out[OUT_NODES];    //修改量矩阵
    double O1[HIDDEN_NODES], O2[OUT_NODES]; //隐层和输出层输出量
    int i, j, k, n;
    double sum;

    double e = PRECISION + 1;

    /* 动态更新权值 */
    double old_e;
    double old_v[IN_NODES][HIDDEN_NODES];
    double old_w[HIDDEN_NODES][OUT_NODES];

    /* 计时器 */
    int time_s = time((time_t*)NULL);

    old_e = 9999;
    printf("LOOP_MAX: %dw\n", LOOP_MAX/10000);
    for (n = 0; e > PRECISION && n < LOOP_MAX; n++) {
        e = 0;
        for (i=0; i < data_size; i++) { 
            for (k=0; k < HIDDEN_NODES; k++) {
                sum = 0;
                for (j = 0; j < IN_NODES; j++) {
                    sum += in[i][j] * v[j][k];    
                }
                //printf("sum: %f\n", sum/256);
                O1[k] = fnet(sum/256);
                //printf("%f\n", O1[k]);
            }
            for (j = 0; j < OUT_NODES; j++) {
                sum = 0;
                for (k = 0; k < HIDDEN_NODES; k++)
                    sum += O1[k] * w[k][j];
                O2[j] = fnet(sum/256);
                //printf("sum: %f\n", sum/256);
                //printf("%f\n", O2[j]);
            }
            for (j = 0; j < OUT_NODES; j++)    //计算输出层的权修改量    
                delta_out[j] = O2[j] * (1 - O2[j]) * (out[i][j] - O2[j]);
            for (j = 0; j < OUT_NODES ; j++) {   //计算输出误差
                //printf("%f \n", (out[i][j] - O2[j]) * (out[i][j] - O2[j]));
                e += (out[i][j] - O2[j]) * (out[i][j] - O2[j]);
                //printf("e:%f\n",e);
            }
            for (k = 0; k < HIDDEN_NODES; k++) {         //计算隐层权修改量
                sum = 0;
                for (j = 0; j < OUT_NODES; j++)
                    sum += w[k][j] * delta_out[j];
                delta_hidden[j] = sum * O1[j] * (1 - O1[j]);
            }
            for (j = 0; j < HIDDEN_NODES; j++)           //修改输出层权矩阵
                for (k = 0; k < OUT_NODES; k++)
                    w[j][k] += alpha * O1[j] * delta_out[k]; 
            for (j = 0; j < IN_NODES; j++)
                for (k = 0; k < HIDDEN_NODES; k++)
                    v[j][k] += alpha * in[i][j] * delta_hidden[k]; 
        }
        if (e < old_e) { //进行权值更新
            old_e = e;
            memcpy(old_v, v, sizeof(double) * IN_NODES * HIDDEN_NODES);
            memcpy(old_w, w, sizeof(double) * HIDDEN_NODES * OUT_NODES);
        } else {    //取消权值更新
            memcpy(v, old_v, sizeof(double) * IN_NODES * HIDDEN_NODES);
            memcpy(w, old_w, sizeof(double) * HIDDEN_NODES * OUT_NODES);
            alpha = 0.99 * alpha;
            //printf("alpha changed:%f\n", alpha);
        }

        if (n % LOG_DEN == 0) {
            /* 写入日志 */
            time_t time_e = time(NULL);
            struct tm *timeinfo;
            timeinfo = localtime(&time_e);
            int seconds = (int)difftime(time_e, time_s);
            int mins = seconds % 3600;
            int secs = mins % 60;
            syslog(LOG_USER|LOG_DEBUG, "%02d:%02d:%02d %02dh%02dm%02ds %dw %f %f\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, seconds/3600, mins/60, secs, n/LOG_DEN, alpha, e);
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
    /* 记录日志 */
    int logfd = open( "nn.log", O_RDWR | O_CREAT | O_APPEND, 0644 );
    close(STDERR_FILENO);
    dup2(logfd, STDERR_FILENO);
    close(logfd);
    openlog(NULL, LOG_PERROR, LOG_DAEMON);

    /* 读取样本数据 */
    FILE *vector_p = NULL;
    if(argc < 2) {
        printf("usage: %s [matrix file] [weight file]\n", argv[0]);
        return 0;
    } else {
        vector_p = fopen(argv[1], "rb");
    }
    if (vector_p == NULL) {
        printf("Error! File %s does not exist.\n", argv[1]);
        exit(0);
    }
    /* 获取数据量 */
    int data_size;
    fread(&data_size, sizeof(int), 1, vector_p);
    /* 输入输出矩阵分配内存 */
    unsigned char **in = (unsigned char**) malloc(sizeof(unsigned char*) * data_size);
    double **out = (double **) malloc(sizeof(double *) * data_size);
    int i,j;
    for(i=0;i<data_size;i++) {
        in[i] = (unsigned char*) malloc(sizeof(unsigned char) * IN_NODES);
        out[i] = (double *) malloc(sizeof(double) * OUT_NODES);
    }
    /* 读入输入输出矩阵 */
    for(i=0;i<data_size;i++) {
        fread(in[i], sizeof(unsigned char), IN_NODES, vector_p);
        fread(out[i], sizeof(double), OUT_NODES, vector_p);
    }
    fclose(vector_p);

    /*
    printf("matrix in:\n");
    for(i=0; i < data_size; i++) {
        for(j=0; j < IN_NODES ; j++) {
            fprintf(stdout, "%d ", in[i][j]);
        }
        printf("\n");
    }
    */

    double v[IN_NODES][HIDDEN_NODES];   //隐含层权值矩阵
    double w[HIDDEN_NODES][OUT_NODES];   //输出层权值矩阵

    vector_p = NULL;
    char *data_file;
    char file_str[] = "wisdom.dat";
    if(argc < 3) {
        data_file = file_str;
        printf("Warning: 使用当前目录下数据文件\n");
    } else {
        data_file = argv[2];
    }
    vector_p = fopen(data_file, "rb+");
    if (vector_p == NULL) { //不存在，使用随机数初始化
        /* 初始化权值矩阵 */
        srand((unsigned)time((time_t *)NULL));
        for (i = 0; i < IN_NODES; i++) {
            for (j = 0; j < HIDDEN_NODES; j++) {
                v[i][j] = rand() / (double)(RAND_MAX);
            }
        }
        for (i = 0; i < HIDDEN_NODES; i++) {
            for (j = 0; j < OUT_NODES; j++) {
                w[i][j] = rand() / (double)(RAND_MAX);
            }
        }
        vector_p = fopen(data_file, "wb");
    } else {    //使用上一次的矩阵
        printf("使用上次矩阵");
        fread(v, HIDDEN_NODES * sizeof(double), IN_NODES, vector_p);
        fread(w, OUT_NODES * sizeof(double), HIDDEN_NODES, vector_p);
        fclose(vector_p);
    }

    /* 保存数据点 */
    FILE *fp = NULL;
    if(argc < 4) {
        fp = fopen("grapher.txt", "w");
    } else {
        fp = fopen(argv[3], "w");
    }

    /* 训练 */
    printf("开始网络训练\n");
    train_bp(v, w, in, out, data_size, vector_p, fp);             //训练bp神经网络

    /* 释放内存 */
    for(i=0;i<data_size;i++) {
        free(in[i]);
        free(out[i]);
    }
    free(in);
    free(out);
    closelog();
    return 0;
}
