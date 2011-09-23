#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#include "config.h"

double fnet(double net);

/* 矩阵类型 */
typedef enum {
    DOUBLE,
    INT,
    UNSIGNED_CHAR,

} mtype;

/* 转置类型 */
typedef enum {
    NORMAL,
    REVERSE,
} rtype;

typedef union
{
    unsigned char **cm;
    double **dm;
    int **im;
} matrix_p;

typedef struct
{
    int m;
    int n;
    double *matrix;
} Matrix;

int matrix_init(int m, int n, Matrix **X_p);

int matrix_copy( Matrix* X, Matrix* Y);

int matrix_free(Matrix *X);

int matrix_set_value(Matrix *X, double value);

int matrix_set_random(Matrix *X);

int matrix_dot_multiply(Matrix* W, double* X, double Y[], rtype type);

int vector_dot_multiply(double* x, double* y, Matrix* A);

int matrix_fnet(double* X, double* Y, int m);

int matrix_fnet_dot(double *X, double *Y, int m);

int matrix_plus(Matrix* A, Matrix* B, Matrix* C, double alpha);

int vector_plus(double* x, double* y, double* z, int m, double alpha);

int matrix_multiply(double* A, double* B, double* C, int m);

int matrix_fanshu(double* X, double* Y, int m, double *result);

int vector_printf(double* X, int m, int level);
