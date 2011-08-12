#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "nn.h"

int train_bp(double v[][HIDDEN_NODES], double w[][OUT_NODES], unsigned char **in, double **out, int data_size) {
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

    for (n = 0; e > PRECISION && n < LOOP_MAX; n++) {
        e = 0;
        old_e = 9999;
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
        if (n % 10000 == 0) {
            printf("次数: %dw 学习率: %f 误差: %f\n", n/10000, alpha, e);
        }
        if (e< old_e) { //进行权值更新
            old_e = e;
            memcpy(old_v, v, sizeof(double) * IN_NODES * HIDDEN_NODES);
            memcpy(old_w, w, sizeof(double) * HIDDEN_NODES * OUT_NODES);
        } else {    //取消权值更新
            memcpy(v, old_v, sizeof(double) * IN_NODES * HIDDEN_NODES);
            memcpy(w, old_w, sizeof(double) * HIDDEN_NODES * OUT_NODES);
            alpha = 0.99 * alpha;
        }
    }
    printf("总共循环次数：%d\n", n);
    int time_e = time((time_t*)NULL);
    int seconds = time_e - time_s;
    printf("耗时：%dh\n", seconds / 3600 );

    printf("调整后的隐层权矩阵：\n");
    print_matrix(v, IN_NODES, HIDDEN_NODES);
    printf("调整后的输出层权矩阵：\n");
    print_matrix(w, HIDDEN_NODES, OUT_NODES);

    return 0;
}

int print_matrix(double **matrix, int h, int w) {
    int i,j;
    for(i=0; i < h; i++) {
        for(j=0; j < w; j++) {
            fprintf(stdout, "%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int data_size = get_data_size();
    unsigned char **in = (unsigned char**) malloc(sizeof(unsigned char*) * data_size);
    double **out = (double **) malloc(sizeof(double *) * data_size);
    int i,j;
    for(i=0;i<data_size;i++) {
        in[i] = (unsigned char*) malloc(sizeof(unsigned char) * IN_NODES);
        out[i] = (double *) malloc(sizeof(double) * OUT_NODES);
    }
    /* 读取样本数据 */
    FILE *vector_p = NULL;
    vector_p = fopen("sample.dat","rb");
    if (vector_p == NULL) {
        printf("Error! File 'sample.dat' does not exist.\n");
        exit(0);
    }
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
    print_matrix(out, data_size, OUT_NODES);
    */

    double v[IN_NODES][HIDDEN_NODES];   //隐含层权值矩阵
    double w[HIDDEN_NODES][OUT_NODES];   //输出层权值矩阵
    /* 初始化权值矩阵 */
    srand((unsigned)time(NULL));
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

    /* 训练 */
    train_bp(v, w, in, out, data_size);             //训练bp神经网络

    /* 保存权值矩阵 */
    vector_p = NULL;
    vector_p = fopen("wisdom.dat","wb");
    fwrite(v, HIDDEN_NODES*8, IN_NODES, vector_p);
    fwrite(w, OUT_NODES*8, HIDDEN_NODES, vector_p);
    fclose(vector_p);

    /* 释放内存 */
    for(i=0;i<data_size;i++) {
        free(in[i]);
        free(out[i]);
    }
    free(in);
    free(out);
    return 0;
}
