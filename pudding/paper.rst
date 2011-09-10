毕业论文相关代码
-----------------

代码

.. sourcecode:: c

    26     Matrix* a1;
    27     matrix_init(in->m, v->n, &a1, DOUBLE);
    28 
    29     Matrix* f1;
    30     matrix_init(a1->m, a1->n, &f1, DOUBLE);
    31 
    32     Matrix* a2;
    33     matrix_init(f1->m, w->n, &a2, DOUBLE);
    34 
    35     Matrix* f2;
    36     matrix_init(a2->m, a2->n, &f2, DOUBLE);

    50    matrix_dot_multiply(in, v, a1);
    51    matrix_fnet(a1, f1);
    52
    53    matrix_dot_multiply(f1, w, a2);
    54    matrix_fnet(a2, f2);
