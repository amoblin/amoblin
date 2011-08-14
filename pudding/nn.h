#include <math.h>
#include "config.h"
#include "utils.h"

#define LOOP_MAX 10000000   //最大循环次数
#define LEARN_RATE  0.1 //学习率
#define PRECISION 0.05  //精度
#define LOG_DEN 10
#define PLOT_DEN 100


double fnet(double net) { //Sigmoid函数,神经网络激活函数
    return 1 / ( 1 + exp( -net ) );
}

