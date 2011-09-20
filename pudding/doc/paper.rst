毕业论文相关代码
-----------------

代码

.. sourcecode:: c

    /* 初始化矩阵 \*/
    /* n1 = in . w1 \*/
    Matrix* n1;
    matrix_init(in->m, w1->n, &n1);

    /* a1 = f(n1) \*/
    Matrix* a1;
    matrix_init(in->m, w1->n, &a1);

    /* n2 = a1 . w2 \*/
    Matrix* n2;
    matrix_init(in->m, w2->n, &n2);

    /* a2 = f(n2) \*/
    Matrix* a2;
    matrix_init(in->m, w2->n, &a2);

    /* diff2 = out - a2 \*/
    Matrix* diff2;
    matrix_init(in->m, w2->n, &diff2);

    /* h2 = _f(n2) = _h(a2) \*/
    Matrix* h2;
    matrix_init(in->m, w2->n, &h2);

    /* s2 = h2 x diff2 \*/
    Matrix* s2;
    matrix_init(in->m, w2->n, &s2);

    /* diff1 = s2 . w2^T \*/
    Matrix* diff1;
    matrix_init(in->m, w2->m, &diff1);

    /* h1 = _f(n1) = _h(a1) \*/
    Matrix* h1;
    matrix_init(in->m, w1->n, &h1);

    /* s1 = h1 x diff1 \*/
    Matrix* s1;
    matrix_init(in->m, w1->n, &s1);

    /* delta1 = in . s1 \*/
    Matrix* delta1;
    matrix_init(w1->m, w1->n, &delta1);

    /* delta2 = a1 . s2 \*/
    Matrix* delta2;
    matrix_init(w2->m, w2->n, &delta2);

        /* 输入正传 \*/
        matrix_dot_multiply(in, w1, n1, NORMAL);
        matrix_fnet(n1, a1);

        matrix_dot_multiply(a1, w2, n2, NORMAL);
        matrix_fnet(n2, a2);

        /* 误差反传 \*/
        matrix_fnet_dot(a2, h2);
        matrix_plus(out, a2, diff2, -1);
        matrix_multiply(h2, diff2, s2);
        matrix_printf(diff1);

        matrix_fnet_dot(a1, h1);
        matrix_dot_multiply(s2, w2, diff1, REVERSE2);
        matrix_multiply(h1, diff1, s1);

        /* 更新权值 \*/
        matrix_dot_multiply(in, s1, delta1, REVERSE1);
        matrix_plus(w1, delta1, w1, alpha * -1);

        matrix_dot_multiply(a1, s2, delta2, REVERSE1);
        matrix_plus(w2, delta2, w2, alpha * -1);

        /* 计算输出误差 \*/
        matrix_fanshu(a2, out, &e);
