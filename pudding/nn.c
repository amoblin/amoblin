#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "nn.h"

typedef struct {       //bp人工神经网络结构
    int h;             //实际使用隐层数量
    double a;          //学习率
    double b;          //精度控制参数
    int L;      //最大循环次数
} bp_nn;

int train_bp(double v[][HIDDEN_NODES], double w[][OUT_NODES], unsigned char in[][IN_NODES], char out[][OUT_NODES]) {
    double alpha = LEARN_RATE;  //学习率
    double delta_hidden[HIDDEN_NODES], delta_out[OUT_NODES];    //修改量矩阵
    double O1[HIDDEN_NODES], O2[OUT_NODES]; //隐层和输出层输出量
    int i, j, k, n;
    double sum;

    double e = PRECISION + 1;
    for (n = 0; e > PRECISION && n < LOOP_MAX; n++) {
        e = 0;
        for (i= 0; i < REAL_DATA_SIZE; i++) { 
            for (k= 0; k < HIDDEN_NODES; k++) {
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
        if (n % 500 == 0) {
            printf("误差 : %f\n", e);
        }
    }
    printf("总共循环次数：%d\n", n);

    /*
    printf("调整后的隐层权矩阵：\n");
    for (i = 0; i < IN_NODES; i++) {    
        for (j = 0; j < HIDDEN_NODES; j++) {
            printf("%f    ", v[i][j]);    
        }
        printf("\n");
    }
    printf("调整后的输出层权矩阵：\n");
    for (i = 0; i < HIDDEN_NODES; i++) {
        for (j = 0; j < OUT_NODES; j++) {
            printf("%f    ", w[i][j]);    
        }
        printf("\n");
    }
    */

    return 0;
}

int print_matrix(unsigned char in[][IN_NODES], char out[][OUT_NODES]) {
    if (!DEBUG) {
        return 0;
    }
    int i,j;
    for(i=0; i<REAL_DATA_SIZE; i++) {
        for(j=0; j < IN_NODES ; j++) {
            fprintf(stdout, "%d ", in[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<REAL_DATA_SIZE; i++) {
        for(j=0; j < OUT_NODES; j++) {
            fprintf(stdout, "%d ", out[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    unsigned char in[REAL_DATA_SIZE][IN_NODES];  //无符号字符型数组，元素范围0～255.两个数字代表一个汉字。
    char out[REAL_DATA_SIZE][OUT_NODES];       //输出向量，1代表连续，0代表分词点。


    double v[IN_NODES][HIDDEN_NODES];   //隐含层权值矩阵
    double w[HIDDEN_NODES][OUT_NODES];   //输出层权值矩阵

    /* 读取样本数据 */
    FILE *vector_p = NULL;
    vector_p = fopen("sample.dat","rb");
    if (vector_p == NULL) {
        printf("Error! File 'sample.dat' does not exist.\n");
        exit(0);
    }
    fread(in, IN_NODES, REAL_DATA_SIZE, vector_p);
    fread(out, OUT_NODES, REAL_DATA_SIZE, vector_p);
    fclose(vector_p);
    
    print_matrix(in, out);

    /* 初始化权值矩阵 */

    //随机数
    srand((unsigned)time(NULL));
    int i,j;
    for (i = 0; i < IN_NODES; i++) {
        for (j = 0; j < HIDDEN_NODES; j++) {
            v[i][j] = rand() / (double)(RAND_MAX);    
            //printf("%f ", v[i][j]);
        }
        //printf("\n ");
    }
    for (i = 0; i < HIDDEN_NODES; i++) {
        for (j = 0; j < OUT_NODES; j++) {
            w[i][j] = rand() / (double)(RAND_MAX);    
            printf("%f ", w[i][j]);
        }
        printf("\n ");
    }

    /* 训练 */
    train_bp(v, w, in, out);             //训练bp神经网络

    /*
    for (i = 0; i < IN_NODES; i++) {
        for (j = 0; j < HIDDEN_NODES; j++) {
            printf("%f ", v[i][j]);
        }
        printf("\n ");
    }
    */
    for (i = 0; i < HIDDEN_NODES; i++) {
        for (j = 0; j < OUT_NODES; j++) {
            printf("%f ", w[i][j]);
        }
        printf("\n ");
    }

    /* 保存权值矩阵 */
    vector_p = NULL;
    vector_p = fopen("wisdom.dat","wb");
    fwrite(v, HIDDEN_NODES, IN_NODES, vector_p);
    fwrite(w, OUT_NODES, HIDDEN_NODES, vector_p);
    fclose(vector_p);

    return 0;
} 

