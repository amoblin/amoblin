#include <math.h>
#include "config.h"

double fnet(double net) { //Sigmoid函数,神经网络激活函数
    return 1 / ( 1 + exp( -net ) );
}

