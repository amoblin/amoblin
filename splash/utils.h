#include <stdio.h>

/* 不用额外存储空间，交换两个数, 这在两个变量为同一个变量时无效 */
#define swap(a,b) ((a)=(a)^(b), (b)=(a)^(b), (a)=(a)^(b))
void swap_f(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

#define min(a,b) ((a) > (b) ? (b) : (a))
#define max(a,b) ((a) > (b) ? (a) : (b))

/* 求众数:出现次数最多的数 */
/* 求中位数: 数据的中间位置数或中间两个数的均值. */

void test_swap() {
    int x=2;
    swap(x, x);
    printf("%d\n", x);
}
