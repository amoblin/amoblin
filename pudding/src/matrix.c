#include "matrix.h"

int matrix_init(int m, int n, Matrix **X_p)
{
    *X_p = (Matrix *) malloc(sizeof(Matrix));
    Matrix *X = *X_p;
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

int matrix_free(Matrix *X)
{
    int i;
    for(i=0; i < X->m; i++) {
        free(X->matrix[i]);
    }
    free(X->matrix);
    return 0;
}

int matrix_set_value(Matrix *X, unsigned int value)
{
    int i;
    for(i = 0; i < X->m; i++) {
        memset(X->matrix[i], value, sizeof(double) * X->n);
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

int matrix_dot_multiply(Matrix *W, Matrix *X, Matrix *Y, rtype type)
{
    matrix_set_value(Y, 0);

    int i, j, k;
    switch(type) {
        case NORMAL:
            if(W->n != X->m) {
                return -1;
            }

            for(i=0; i < W->m; i++) {
                for(j=0; j < X->n; j++) {
                    for(k=0; k < W->n; k++) {
                        Y->matrix[i][j] += W->matrix[i][k] * X->matrix[k][j];
                    }
                }
            }
            break;
        case REVERSE1:
            if(W->m != X->m) {
                return -1;
            }

            for(i=0; i < W->n; i++) {
                for(j=0; j < X->n; j++) {
                    for(k=0; k < W->m; k++) {
                        Y->matrix[i][j] += W->matrix[i][k] * X->matrix[k][j];
                    }
                }
            }
            break;
        case REVERSE2:
            if(W->n != X->n) {
                return -1;
            }

            for(i=0; i < W->m; i++) {
                for(j=0; j < X->m; j++) {
                    for(k=0; k < W->n; k++) {
                        Y->matrix[i][j] += W->matrix[i][k] * X->matrix[k][j];
                    }
                }
            }
            break;
        default:
            break;
    }
    return 0;
}

int matrix_fnet(Matrix *X, Matrix *Y) {
    assert(X->m == Y->m);
    assert(X->n == Y->n);

    int i,j;
    for(i=0; i< X->m; i++) {
        for(j=0; j < X->n; j++) {
            Y->matrix[i][j] = fnet(X->matrix[i][j]);
        }
    }
    return 0;
}

int matrix_plus(Matrix* A, Matrix* B, Matrix* C, double alpha) {
    assert(A->m == B->m);
    assert(B->m == C->m);
    assert(A->n == B->n);
    assert(B->n == C->n);
    int i,j;
    for(i=0; i< A->m; i++) {
        for(j= 0; j< A->n; j++) {
            C->matrix[i][j] = A->matrix[i][j] + alpha * B->matrix[i][j];
        }
    }
    return 0;
}

int matrix_multiply(Matrix *A, Matrix *B, Matrix *C)
{
    if(A->m != B->m || A->n != B->n) {
        return -1;
    }

    int i,j;
    for(i = 0; i < A->m; i++) {
        for(j=0; j< A->n; j++) {
            C->matrix[i][j] = A->matrix[i][j] * B->matrix[i][j];
        }
    }
}

int matrix_fanshu(Matrix* X, Matrix* Y, double *result) {
    assert(X->m == Y->m);
    assert(X->n == Y->n);

    int i,j;
    *result = 0;
    for(i= 0; i< X->m; i++) {
        for(j= 0; j< X->n; j++) {
            diff = X->matrix[i][j] - Y->matrix[i][j];
            result += diff * diff;
        }
    }
    return 0;
}
