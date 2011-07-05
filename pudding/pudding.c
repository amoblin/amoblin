#include <stdio.h>
#include "nn.h"

int main(int argc, char *argv[])
{
    float in[IN_NODES];
    double O1[50]; 
    double O2[OUT_NODES]; //O1为隐层输出,O2为输出层输出

    int i, j;
    for (i = 0; i < IN_NODES; i++) {
        scanf("%f", &in[i]);
    }
    for (i = 0; i < IN_NODES; i++) {
        printf("%f", in[i]);
    }
    double temp;
    for (i = 0; i < HIDDEN_NODES; i++) {
        temp = 0;
        for (j = 0; j < IN_NODES; j++)
            temp += in[j] * v[j][i];
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
    return 1;
}
