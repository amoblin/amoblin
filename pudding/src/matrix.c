#include "matrix.h"

#define pos(x,y,m) matrix[(x)*(m)+(y)]

/* Sigmoid函数,神经网络激活函数 */
double fnet(double net) {
    return 1 / ( 1 + exp( -net ) );
}

Matrix *matrix_init(int m, int n)
{
    Matrix *X = NULL;
    X = (Matrix *) malloc(sizeof(Matrix));
    if (NULL == X) {
        exit(0);
    }
    int i;
    X->matrix = NULL;
    X->matrix = (double *) malloc(sizeof(double) * m * n );
    if(NULL == X->matrix) {
        exit(0);
    }
    memset(X->matrix, 0, sizeof(double) * m * n);
    X->m = m;
    X->n = n;

    return X;
}

int matrix_copy( Matrix* X, Matrix* Y) {
    assert( X->m == Y->m);
    assert( X->n == Y->n);
    int i, j;
    for( i= 0; i< X->m; i++) {
        for( j= 0; j< X->n; j++) {
            Y->pos(i,j,Y->n) = X->pos(i,j,X->n);
        }
    }
    return 0;
}

int matrix_free(Matrix *X)
{
    int i;
    free(X->matrix);
    free(X);
    return 0;
}

int matrix_set_value(Matrix *X, double value)
{
    int i,j;
    for(i = 0; i < X->m; i++) {
        for(j= 0; j< X->n; j++) {
            X->pos(i,j,X->n) = value;
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
            X->pos(i,j,X->n) = rand() / (double)(RAND_MAX);
        }
    }
    return 0;
}

int matrix_dot_multiply(Matrix *W, double *X, double *Y, rtype type)
{
    int i, j;
    switch(type) {
        case NORMAL:
            //memset(Y, 0, sizeof(double) * W->n);
            for(i=0; i < W->m; i++) {
                Y[i] = 0;
                for(j=0; j < W->n; j++) {
                    Y[i] += W->pos(i,j,W->n) * X[j];
                }
                //d_printf(3, "%2.1f ", Y[i]);
            }
            //d_printf(3, "\n");
            break;
        case REVERSE:
            //memset(Y, 0, sizeof(double) * W->m);
            for( i = 0; i < W->n; i++) {
                Y[i] = 0;
                for( j = 0; j < W->m; j++) {
                    Y[i] += W->pos(j,i,W->m) * X[j];
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
        Y[i] = fnet(X[i]/10);
        d_printf(1, "%2.1f ", X[i]);
        d_printf(1, "%2.1f ", Y[i]);
    }
    d_printf(1, "\n");
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
            C->pos(i,j, C->n) = A->pos(i,j, A->n) + alpha * B->pos(i,j,B->n);
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

int vector_norm(double* X, double* Y, int m, double *result) {
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
            A->pos(i,j,A->n) = x[i] * y[j];
        }
    }
    return 0;
}

int vector_print(double* X, int m, int level) {
    int i;
    for (i = 0; i < m; i++) {
        d_printf(level, "%f ", X[i]);
    }
    d_printf(level, "\n");
}

int matrix_print(Matrix* X) {
    int i,j;
    for( i=0; i< X->m; i++) {
        for( j=0; j< X->n; j++) {
            printf("%2.1f ", X->pos(i, j, X->n) );
        }
    }
    printf("\n");
}
