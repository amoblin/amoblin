#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <string.h>
#include <math.h>

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
    REVERSE1,
    REVERSE2,
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
    double **matrix;
} Matrix;

int matrix_init(int m, int n, Matrix **X_p);

int matrix_copy( Matrix* X, Matrix* Y);

int matrix_free(Matrix *X);

int matrix_set_value(Matrix *X, double value);

int matrix_set_random(Matrix *X);

int matrix_dot_multiply(Matrix *W, Matrix *X, Matrix *Y, rtype type);

int matrix_fnet(Matrix *X, Matrix *Y);

int matrix_plus(Matrix* A, Matrix* B, Matrix* C, double alpha);

int matrix_multiply(Matrix *A, Matrix *B, Matrix *C);

int matrix_fanshu(Matrix* X, Matrix* Y, double *result);

int matrix_printf(Matrix* X, int level);
