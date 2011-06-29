#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#include "config.h"

typedef struct {       //bp人工神经网络结构
    int h;             //实际使用隐层数量
    double a;          //学习率
    double b;          //精度控制参数
    int L;      //最大循环次数
} bp_nn;

double fnet(double net) { //Sigmoid函数,神经网络激活函数
    return 1/(1+exp(-net));
}

int train_bp(double v[][HIDDEN_NODES], double w[][OUT_NODES], unsigned char in[][IN_NODES], char out[][OUT_NODES]) {
    double f;                      //精度控制参数
    double a;                      //学习率
    int h ;                         //隐层节点数
    //double v[IN_NODES][HIDDEN_NODES], w[HIDDEN_NODES][OUT_NODES]; //权矩阵
    double delta_hidden[HIDDEN_NODES], delta_out[OUT_NODES];         //修改量矩阵
    double O1[HIDDEN_NODES], O2[OUT_NODES];             //隐层和输出层输出量
    int i, j, k, n;
    double sum;

    double e = f + 1;
    for (n = 0; e > f && n < LOOP_MAX; n++) {
        e = 0;
        for (i= 0; i < REAL_DATA_SIZE; i++) { 
            for (k= 0; k < HIDDEN_NODES; k++) {
                sum = 0;
                for (j = 0; j < IN_NODES; j++) {
                    sum += in[i][j] * v[j][k];    
                }
                printf("sum: %f\n", sum/256);
                O1[k] = fnet(sum/256);
                printf("%f\n", O1[k]);
            }
            for (j = 0; j < OUT_NODES; j++) {
                sum = 0;
                for (k = 0; k < HIDDEN_NODES; k++)
                    sum += O1[k] * w[k][j];
                O2[j] = fnet(sum/256);
                printf("sum: %f\n", sum/256);
                printf("%f\n", O2[j]);
            }
            for (j = 0; j < OUT_NODES; j++)    //计算输出层的权修改量    
                delta_out[j] = O2[j] * (1 - O2[j]) * (out[i][j] - O2[j]);
            for (j = 0; j < OUT_NODES ; j++) {   //计算输出误差
                printf("%f \n", (out[i][j] - O2[j]) * (out[i][j] - O2[j]));
                e = e + (out[i][j] - O2[j]) * (out[i][j] - O2[j]);
            }
            for (k = 0; k < HIDDEN_NODES; k++) {         //计算隐层权修改量
                sum = 0;
                for (j = 0; j < OUT_NODES; j++)
                    sum += w[k][j] * delta_out[j];
                delta_hidden[j] = sum * O1[j] * (1 - O1[j]);
            }
            for (j = 0; j < HIDDEN_NODES; j++)           //修改输出层权矩阵
                for (k = 0; k < OUT_NODES; k++)
                    w[j][k] += a * O1[j] * delta_out[k]; 
            for (j = 0; j < IN_NODES; j++)
                for (k = 0; k < HIDDEN_NODES; k++)
                    v[j][k] += a * in[i][j] * delta_hidden[k]; 
        }
        if (n % 10 == 0) {
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
/*

int UseBp(bp_nn *bp) {    //使用bp网络
    float Input[IN_NODES];
    double O1[50]; 
    double O2[OUT_NODES]; //O1为隐层输出,O2为输出层输出
    while (1) {           //持续执行，除非中断程序
        printf("请输入一句话：\n");
        int i, j;
        for (i = 0; i < IN_NODES; i++)
            scanf("%f", &Input[i]);
        double temp;
        for (i = 0; i < (*bp).h; i++) {
            temp = 0;
            for (j = 0; j < IN_NODES; j++)
                temp += Input[j] * (*bp).v[j][i];
            O1[i] = fnet(temp);
        }
        for (i = 0; i < OUT_NODES; i++) {
            temp = 0;
            for (j = 0; j < (*bp).h; j++)
                temp += O1[j] * (*bp).w[j][i];
            O2[i] = fnet(temp);
        }
        printf("结果：   ");
        for (i = 0; i < OUT_NODES; i++)
            printf("%.3f ", O2[i]);
        printf("\n");
    }
    return 1;
}
*/

int print_matrix(unsigned char in[][SEN_LEN*2], char out[][SEN_LEN]) {
    if (!DEBUG) {
        return 0;
    }
    int i,j;
    for(i=0; i<REAL_DATA_SIZE; i++) {
        for(j=0; j < SEN_LEN * 2 ; j++) {
            fprintf(stdout, "%d ", in[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<REAL_DATA_SIZE; i++) {
        for(j=0; j < SEN_LEN; j++) {
            fprintf(stdout, "%d ", out[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    unsigned char in[REAL_DATA_SIZE][SEN_LEN * 2];  //无符号字符型数组，元素范围0～255.两个数字代表一个汉字。
    char out[REAL_DATA_SIZE][SEN_LEN];       //输出向量，1代表连续，0代表分词点。


    double v[IN_NODES][HIDDEN_NODES];   //隐含层权值矩阵
    double w[HIDDEN_NODES][OUT_NODES];   //输出层权值矩阵

    /* 读取输入层数据 */
    FILE *vector_p = NULL;
    vector_p = fopen("in.dat","rb");
    if (vector_p == NULL) {
        printf("Error! File 'in.dat' does not exist.\n");
        exit(0);
    }
    fread(in, SEN_LEN * 2, REAL_DATA_SIZE, vector_p);
    fclose(vector_p);
    
    /* 读取输出层数据 */
    vector_p = fopen("out.dat","rb");
    if (vector_p == NULL) {
        printf("Error! File 'out.dat' does not exist.\n");
        exit(0);
    }
    fread(out, SEN_LEN, REAL_DATA_SIZE, vector_p);
    fclose(vector_p);

    print_matrix(in, out);

    /* 初始化权值矩阵 */

    //随机数
    printf("%d\n", (unsigned) time(NULL));
    srand((unsigned)time(NULL));
    printf("%d\n",rand());
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
            //printf("%f ", v[i][j]);
        }
        //printf("\n ");
    }

    /* 训练 */
    train_bp(v, w, in, out);             //训练bp神经网络
    //UseBp(&bp);                     //测试bp神经网络

    return 0;
} 

