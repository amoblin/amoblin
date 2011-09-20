#include "matrix.h"

/* Sigmoid函数,神经网络激活函数 */
double fnet(double net) {
    return 1 / ( 1 + exp( -net ) );
}

int matrix_init(int m, int n, Matrix **X_p)
{
    Matrix *X = NULL;
    X = (Matrix *) malloc(sizeof(Matrix));
    if (NULL == X) {
        return -1;
    }
    *X_p = X;
    int i;
    X->matrix = NULL;
    X->matrix = (double **) malloc(sizeof(double*) * m );
    if(NULL == X->matrix) {
        return -1;
    }
    for(i = 0; i < m; i++) {
        X->matrix[i] = NULL;
        X->matrix[i] = (double*) malloc(sizeof(double) * n);
        if(NULL == X->matrix[i]) {
            return -1;
        }
        memset(X->matrix[i], 0, sizeof(double) * n);
        X->matrix[i][0] = 0;
    }
    X->m = m;
    X->n = n;
    return 0;
}

int matrix_copy( Matrix* X, Matrix* Y) {
    assert( X->m == Y->m);
    assert( X->n == Y->n);
    int i, j;
    for( i= 0; i< X->m; i++) {
        for( j= 0; j< X->n; j++) {
            Y->matrix[i][j] = X->matrix[i][j];
        }
    }
    return 0;
}

int matrix_free(Matrix *X)
{
    int i;
    for(i=0; i < X->m; i++) {
        free(X->matrix[i]);
    }
    free(X->matrix);
    free(X);
    return 0;
}

int matrix_set_value(Matrix *X, double value)
{
    int i,j;
    for(i = 0; i < X->m; i++) {
        for(j= 0; j< X->n; j++) {
            X->matrix[i][j] = value;
        }
    }
    return 0;
}

int matrix_set_random(Matrix *X)
{
    int i;
    int j;
    srand((unsigned)time((time_t *)NULL));
    for (i = 0; i < X->m; i++) {
        for (j = 0; j < X->n; j++) {
            X->matrix[i][j] = rand() / (double)(RAND_MAX);
        }
    }
    return 0;
}

int matrix_dot_multiply(Matrix *W, double *X, double *Y, rtype type)
{

    int i, j;
    switch(type) {
        case NORMAL:
            memset(Y, 0, sizeof(double) * W->n);
            for(i=0; i < W->m; i++) {
                for(j=0; j < W->n; j++) {
                    Y[i] += W->matrix[i][j] * X[j];
                }
            }
            break;
        case REVERSE:
            memset(Y, 0, sizeof(double) * W->m);
            for( i = 0; i < W->n; i++) {
                for( j = 0; j < W->m; j++) {
                    Y[i] += W->matrix[j][i] * X[j];
                }
            }
            break;
        default:
            break;
    }
    return 0;
}

int matrix_fnet(double* X, double* Y, int m) {
    int i;
    for (i = 0; i < m; i++) {
        Y[i] = fnet(X[i]);
    }
    return 0;
}

int matrix_fnet_dot(double *X, double *Y, int m) {
    int i;
    for (i = 0; i < m; i++) {
        Y[i] = (1- X[i]) * X[i];
    }
    return 0;
}

int vector_plus(double* x, double* y, double* z, int m, double alpha) {
    int i;
    for (i = 0; i < m; i++) {
        z[i] = x[i] + alpha * y[i];
    }
    return 0;
}

int matrix_plus(Matrix* A, Matrix* B, Matrix* C, double alpha) {
    assert(A->m == B->m);
    assert(A->n == B->n);
    assert(B->m == C->m);
    assert(B->n == C->n);
    int i, j;
    for (i = 0; i < A->m; i++) {
        for (j = 0; j < A->n; j++) {
            C->matrix[i][j] = A->matrix[i][j] + alpha * B->matrix[i][j];
        }
    }
    return 0;
}

int matrix_multiply(double* A, double* B, double* C, int m) {
    int i;
    for(i = 0; i < m; i++) {
        C[i] = A[i] * B[i];
    }
}

int matrix_fanshu(double* X, double* Y, int m, double *result) {
    int i;
    double diff;
    double e = 0;
    for (i = 0; i < m; i++) {
        diff = X[i] - Y[i];
        e += diff * diff;
    }
    *result = e;
    return 0;
}

int vector_dot_multiply(double* x, double* y, Matrix* A) {
    int i,j;
    for (i = 0; i < A->m; i++) {
        for (j = 0; j < A->n; j++) {
            A->matrix[i][j] = x[i] * y[j];
        }
    }
    return 0;
}

int vector_printf(double* X, int m, int level) {
    int i;
    for (i = 0; i < m; i++) {
        d_printf(level, "%2.1f ", X[i]);
    }
    d_printf(level, "\n");
}
