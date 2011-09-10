#include <math.h>
#include "config.h"
#include "utils.h"

#define LOOP_MAX 100000000   //最大循环次数
#define LOG_DEN 100
#define LEARN_RATE  1.9 //学习率
#define PRECISION 0.05  //精度
#define PLOT_DEN 100


double fnet(double net) { //Sigmoid函数,神经网络激活函数
    return 1 / ( 1 + exp( -net ) );
}

/* 仅对DOUBLE型矩阵 */
int matrix_fnet(Matrix *X, Matrix *Y) {
    int i,j;
    for(i=0; i< X->m; i++) {
        for(j=0; j < X->n; j++) {
            Y->matrix.dm[i][j] = fnet(X->matrix.dm[i][j]);
        }
    }
}
