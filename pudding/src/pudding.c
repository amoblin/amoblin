#include <stdio.h>
#include "nn.h"
#define LEFT_B 0.3
#define RIGHT_B 0.7

int usage(char *argv[])
{
    printf("usage: %s [network matrix] [sentence]\n", argv[0]);
}

int read_weight(double v[][HIDDEN_NODES], double w[][OUT_NODES], FILE *vector_p)
{
    fread(v, HIDDEN_NODES * sizeof(double), IN_NODES, vector_p);
    fread(w, OUT_NODES * sizeof(double), HIDDEN_NODES, vector_p);
    fclose(vector_p);

    int i,j;
    d_printf(1, "matrix v is: \n");
    for (i = 0; i < IN_NODES; i++) {
        for (j = 0; j < HIDDEN_NODES; j++) {
            d_printf(1, "%f ", v[i][j]);
        }
        d_printf(1, "\n ");
    }
    d_printf(1, "matrix w is: \n");
    for (i = 0; i < HIDDEN_NODES; i++) {
        for (j = 0; j < OUT_NODES; j++) {
            d_printf(1, "%f ", w[i][j]);
        }
        d_printf(1, "\n ");
    }
    return 0;
}

int use_nn(double v[][HIDDEN_NODES], double w[][OUT_NODES], unsigned char *in, double *out) {
    double O1[HIDDEN_NODES];
    double sum;
    int i,j;
    for (i = 0; i < HIDDEN_NODES; i++) {
        sum = 0;
        for (j = 0; j < IN_NODES; j++) {
            sum += in[j] * v[j][i];
        }
        O1[i] = fnet(sum/256);
    }
    for (i = 0; i < OUT_NODES; i++) {
        sum = 0;
        for (j = 0; j < HIDDEN_NODES; j++)
            sum += O1[j] * w[j][i];
        out[i] = fnet(sum/256);
    }
}

int pudding(unsigned char sentence[], double v[][HIDDEN_NODES], double w[][OUT_NODES])
{
    /* 整句utf8转unicode */
    unsigned char tmp_in[UNI_LEN];
    double tmp_out[SEN_LEN];
    unsigned char binary_in[BIN_LEN];
    utf82unicode(sentence, tmp_in, tmp_out);
    unicode2binary(tmp_in, binary_in);
    int length = strlen(tmp_in)/2;

    /* 4字为一组输入，有out_size组 */
    unsigned char in[IN_NODES];
    int out_size = length - 3;
    double** out = (double **) malloc(sizeof(double *) * out_size);

    int i,j;
    for(i=0;i<out_size;i++) {
        out[i] = (double *) malloc(sizeof(double) * OUT_NODES);
        memcpy(in, binary_in+i*16, sizeof(unsigned char) * IN_NODES);
        use_nn(v, w, in, out[i]);
        for(j=0; j<OUT_NODES; j++) {
            d_printf(1, "%f ", out[i][j]);
        }
        d_printf(1, "\n");
    }
    return 0;
    /*
    j = 0;
    for( i=0; i< OUT_NODES; i++) {
        if( out[i] <= LEFT_B ) {
            printf("\n%f\n", out[i]);
        } else if( out[i] >= RIGHT_B ) {
            printf(" ");
            int length;
            get_utf8_bytes(sentence[j], &length);
            printf("%f ", out[i]);
            print_u(sentence, j, length);
            j = j + length;
        }
        else {
            printf("\n Error! %f can not be adjusted.\n", out[i]);
        }
    }
    return 0;
    */
}

int main(int argc, char *argv[])
{
    /* 参数处理 */
    unsigned char sentence[UTF8_LEN];
    char data_file[128];
    char ch;
    int flag = 0;
    do {
        ch = getopt(argc, argv, "l:s:h");
        switch(ch) {
            case 'l':
                strncpy(data_file, optarg, sizeof(data_file) - 1);
                flag++;
                break;
            case 's':
                strncpy(sentence, optarg, sizeof(sentence) - 1);
                flag++;
                break;
            case 'h':
            default:
                usage(argv);
                break;
        }
    } while(-1 != ch);
    if( 2 > flag) {
        usage(argv);
        return 0;
    }

    double v[IN_NODES][HIDDEN_NODES];
    double w[HIDDEN_NODES][OUT_NODES];
    FILE *vector_p = NULL;
    vector_p = fopen(data_file, "rb");
    if (NULL == vector_p) {
        printf("Error! %s does not exist.\n", data_file);
        exit(0);
    }
    read_weight(v, w, vector_p);

    pudding(sentence, v, w);

    printf("\n");
    return 0;
}
