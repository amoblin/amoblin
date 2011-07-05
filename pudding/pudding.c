#include <stdio.h>
#include "nn.h"
#include "utils.h"

int read_weight(double v[][HIDDEN_NODES], double w[][OUT_NODES])
{
    FILE *vector_p = NULL;
    vector_p = fopen("wisdom.dat","rb");
    if (vector_p == NULL) {
        printf("Error! wisdom.dat does not exist.");
    }
    fread(v, HIDDEN_NODES, IN_NODES, vector_p);
    fread(w, OUT_NODES, HIDDEN_NODES, vector_p);
    fclose(vector_p);

    /*
    for (i = 0; i < IN_NODES; i++) {
        for (j = 0; j < HIDDEN_NODES; j++) {
            printf("%f ", v[i][j]);
        }
        printf("\n ");
    }
    for (i = 0; i < HIDDEN_NODES; i++) {
        for (j = 0; j < OUT_NODES; j++) {
            printf("%f ", w[i][j]);
        }
        printf("\n ");
    }
    */
}

int pudding(char sentence[], double v[][HIDDEN_NODES], double w[][OUT_NODES], char out[])
{
    /* utf8转unicode */
    unsigned char in[IN_NODES];

    int i,j;
    for(i=0; i < OUT_NODES; i++) {
        out[i] = 0;
    }
    utf8_to_unicode(sentence, in, out);

    double O1[50]; 
    double O2[OUT_NODES];

    double sum;
    for (i = 0; i < IN_NODES; i++) {
        sum = 0;
        for (j = 0; j < HIDDEN_NODES; j++)
            sum += in[i] * v[i][j];
        O1[j] = fnet(sum/256);
    }
    for (i = 0; i < HIDDEN_NODES; i++) {
        sum = 0;
        for (j = 0; j < OUT_NODES; j++)
            sum += O1[i] * w[i][j];
        O2[j] = fnet(sum/256);
    }
    for (i = 0; i < OUT_NODES; i++) {
        printf("%.3f ", O2[i]);
    }

    for(i=0; i < OUT_NODES; i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    char sentence[SEN_LEN];
    scanf("%s", sentence);

    double v[IN_NODES][HIDDEN_NODES];
    double w[HIDDEN_NODES][OUT_NODES];
    read_weight(v, w);

    char out[OUT_NODES];
    pudding(sentence, v, w, out);
    return 0;
}
