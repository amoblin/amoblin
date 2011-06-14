#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

#define OUT_COUT 2     //输出向量维数
#define IN_COUT 3     //输入向量维数
#define COUT     6     //样本数量

typedef struct {       //bp人工神经网络结构
    int h;             //实际使用隐层数量
    double v[IN_COUT][50];   //隐藏层权矩阵i,隐层节点最大数量为50
    double w[50][OUT_COUT];   //输出层权矩阵
    double a;          //学习率
    double b;          //精度控制参数
    int LoopCout;      //最大循环次数
} bp_nn;

double fnet(double net) { //Sigmoid函数,神经网络激活函数
    return 1/(1+exp(-net));
}

int InitBp(bp_nn *bp) { //初始化bp网络
    
    printf("请输入隐层节点数，最大数为100：\n");    
    scanf("%d", &(*bp).h);
    
    printf("请输入学习率：\n");
    scanf("%lf", &(*bp).a);    //(*bp).a为double型数据，所以必须是lf

    printf("请输入精度控制参数：\n");
    scanf("%lf", &(*bp).b);

    printf("请输入最大循环次数：\n");
    scanf("%d", &(*bp).LoopCout);

    int i, j;
    srand((unsigned)time(NULL));
    for (i = 0; i < IN_COUT; i++) 
        for (j = 0; j < (*bp).h; j++)
            (*bp).v[i][j] = rand() / (double)(RAND_MAX);    
    for (i = 0; i < (*bp).h; i++) 
        for (j = 0; j < OUT_COUT; j++)
            (*bp).w[i][j] = rand() / (double)(RAND_MAX);    
    
    return 1;
}

int TrainBp(bp_nn *bp, float x[COUT][IN_COUT], int y[COUT][OUT_COUT]) {
//训练bp网络，样本为x，理想输出为y
    double f = (*bp).b;                      //精度控制参数
    double a = (*bp).a;                      //学习率
    int h = (*bp).h;                         //隐层节点数
    double v[IN_COUT][50], w[50][OUT_COUT]; //权矩阵
    double ChgH[50], ChgO[OUT_COUT];         //修改量矩阵
    double O1[50], O2[OUT_COUT];             //隐层和输出层输出量
    int LoopCout = (*bp).LoopCout;           //最大循环次数
    int i, j, k, n;
    double temp;

    for (i = 0; i < IN_COUT; i++)            // 复制结构体中的权矩阵 
        for (j = 0; j < h; j++)
            v[i][j] = (*bp).v[i][j];
    for (i = 0; i < h; i++)
        for (j = 0; j < OUT_COUT; j++)
            w[i][j] = (*bp).w[i][j];
    
    double e = f + 1;
    for (n = 0; e > f && n < LoopCout; n++) { //对每个样本训练网络
        e = 0;
        for (i= 0; i < COUT; i++) { 
            for (k= 0; k < h; k++) {          //计算隐层输出向量
                temp = 0;
                for (j = 0; j < IN_COUT; j++)
                    temp = temp + x[i][j] * v[j][k];    
                O1[k] = fnet(temp);
            }
            for (k = 0; k < OUT_COUT; k++) { //计算输出层输出向量
                temp = 0;
                for (j = 0; j < h; j++)
                    temp = temp + O1[j] * w[j][k];
                O2[k] = fnet(temp);
            }
            for (j = 0; j < OUT_COUT; j++)    //计算输出层的权修改量    
                ChgO[j] = O2[j] * (1 - O2[j]) * (y[i][j] - O2[j]);
            for (j = 0; j < OUT_COUT ; j++)   //计算输出误差
                e = e + (y[i][j] - O2[j]) * (y[i][j] - O2[j]);
            for (j = 0; j < h; j++) {         //计算隐层权修改量
                temp = 0;
                for (k = 0; k < OUT_COUT; k++)
                    temp = temp + w[j][k] * ChgO[k];
                ChgH[j] = temp * O1[j] * (1 - O1[j]);
            }
            for (j = 0; j < h; j++)           //修改输出层权矩阵
                for (k = 0; k < OUT_COUT; k++)
                    w[j][k] = w[j][k] + a * O1[j] * ChgO[k]; 
            for (j = 0; j < IN_COUT; j++)
                for (k = 0; k < h; k++)
                    v[j][k] = v[j][k] + a * x[i][j] * ChgH[k]; 
        }
        if (n % 10 == 0)
            printf("误差 : %f\n", e);
    }
    printf("总共循环次数：%d\n", n);
    printf("调整后的隐层权矩阵：\n");
    for (i = 0; i < IN_COUT; i++) {    
        for (j = 0; j < h; j++)
            printf("%f    ", v[i][j]);    
        printf("\n");
    }
    printf("调整后的输出层权矩阵：\n");
    for (i = 0; i < h; i++) {
        for (j = 0; j < OUT_COUT; j++)
            printf("%f    ", w[i][j]);    
        printf("\n");
    }
    for (i = 0; i < IN_COUT; i++)             //把结果复制回结构体 
        for (j = 0; j < h; j++)
            (*bp).v[i][j] = v[i][j];
    for (i = 0; i < h; i++)
        for (j = 0; j < OUT_COUT; j++)
            (*bp).w[i][j] = w[i][j];
    printf("bp网络训练结束！\n");

    return 1;
}

int UseBp(bp_nn *bp) {    //使用bp网络
    float Input[IN_COUT];
    double O1[50]; 
    double O2[OUT_COUT]; //O1为隐层输出,O2为输出层输出
    while (1) {           //持续执行，除非中断程序
        printf("请输入3个数：\n");
        int i, j;
        for (i = 0; i < IN_COUT; i++)
            scanf("%f", &Input[i]);
        double temp;
        for (i = 0; i < (*bp).h; i++) {
            temp = 0;
            for (j = 0; j < IN_COUT; j++)
                temp += Input[j] * (*bp).v[j][i];
            O1[i] = fnet(temp);
        }
        for (i = 0; i < OUT_COUT; i++) {
            temp = 0;
            for (j = 0; j < (*bp).h; j++)
                temp += O1[j] * (*bp).w[j][i];
            O2[i] = fnet(temp);
        }
        printf("结果：   ");
        for (i = 0; i < OUT_COUT; i++)
            printf("%.3f ", O2[i]);
        printf("\n");
    }
    return 1;
}

int main()
{
    float x[COUT][IN_COUT] = {{0.8,0.5,0}, 
                       {0.9,0.7,0.3},
                   {1,0.8,0.5},
                       {0,0.2,0.3},
                   {0.2,0.1,1.3},
                       {0.2,0.7,0.8}}; //训练样本
    int y[COUT][OUT_COUT] = {{0,1},
                   {0,1},
                 {0,1},
                     {1,0},
                     {1,0},
                 {1,0}};          //理想输出
    bp_nn bp;

    InitBp(&bp);                    //初始化bp网络结构
    TrainBp(&bp, x, y);             //训练bp神经网络
    UseBp(&bp);                     //测试bp神经网络

    return 1;
} 

