#include <stdio.h>
#include "nn.h"

int main(int argc, char *argv[])
{
    float in[IN_NODES];
    double O1[50]; 
    double O2[OUT_NODES];

    double v[IN_NODES][HIDDEN_NODES];
    double w[HIDDEN_NODES][OUT_NODES];
    FILE *vector_p = NULL;
    vector_p = fopen("wisdom.dat","rb");
    if (vector_p == NULL) {
        printf("Error! wisdom.dat does not exist.");
    }
    fread(v, HIDDEN_NODES, IN_NODES, vector_p);
    fread(w, OUT_NODES, HIDDEN_NODES, vector_p);
    fclose(vector_p);

    int i,j;
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

    for (i = 0; i < IN_NODES; i++) {
        scanf("%f", &in[i]);
    }
    for (i = 0; i < IN_NODES; i++) {
        printf("%f", in[i]);
    }

    double sum;
    for (i = 0; i < HIDDEN_NODES; i++) {
        sum = 0;
        for (j = 0; j < IN_NODES; j++)
            sum += in[j] * v[j][i];
        O1[i] = fnet(sum);
    }
    for (i = 0; i < OUT_NODES; i++) {
        sum = 0;
        for (j = 0; j < HIDDEN_NODES; j++)
            sum += O1[j] * w[j][i];
        O2[i] = fnet(sum);
    }
    for (i = 0; i < OUT_NODES; i++)
        printf("%.3f ", O2[i]);
    printf("\n");
    return 1;
}
