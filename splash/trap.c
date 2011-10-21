#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int p = 1;

void print_str(char *str, int n) {
    int i=0;
    for(; i<n; i++) {
        printf("%d ", str[i]);
    }
    printf("\n");
}

void set_string(char str[]) {
    printf("now in function:\n");
    /* 形参是指针,指向实参 */
    printf("size of str is %d\n", sizeof(str));
    printf("strlen str is %d\n", strlen(str));
}

void sizeof_and_strlen() {
    /* 全局变量,静态变量(静态存储区),自动初始化为0,局部变量(栈变量),堆变量,上次操作此地址的遗留数据. */
    char blank[20];
    print_str(blank, 20);

    /* 也应该是随机串,但centos下却是零串 */
    char *malloc_str = (char*) malloc(20);
    print_str(malloc_str, 20);

    /* 不能这样写,编译会警告,运行会段错误 */
    //char *a = {'a','b','c'};
    
    /* 溢出串 */
    char a[3] = "abc";
    printf("%s\n", a);
    printf("%d\n", sizeof(a));
    printf("%d\n", strlen(a));

    /* 零串 */
    char zero[10] = {0};
    print_str(zero, 10);

    char str[] = "123456789abcdef";
    /* 数组首地址, sizeof统计实际占用的字节数,包括'\0' */
    printf("size of str is %d\n", sizeof(str));
    printf("strlen str is %d\n", strlen(str));

    char *p = "123456789abcdef";
    /* 运行会段错误. 企图访问只读区域. */
    //p[0] = '0';

    /* 指针类型, sizeof值依电脑位数而定,32位机是4字节,64位机是8字节*/
    printf("size of p is %d\n", sizeof(p));
    printf("strlen p is %d\n", strlen(p));

    /* */
    str[0] = '0';
    printf("%s\n", str);

    /* 不可变串 */
    /* const_str不可变:两种实现方式 */
    //const (char *) const_str = str;
    char* const const_str2 = str;
    
    /* 限定 *str_p 不可变 */
    const char *str_p = str;
    str_p++;
    printf("%s\n", str_p);

    /* 都不可变 */
    const char* const const_str3 = str;

    set_string(str);
}

void str_copy() {
    char *str =(char*) malloc(3);
    char *tmp = "ab";

    /* */
    memset(str, 0, strlen(str));
    memcpy(str, tmp, strlen(tmp));
    printf("%s\n", str);

    /* */
    memset(str, 0, strlen(str));
    strncpy(str, tmp, strlen(tmp)+1);
    printf("%s\n", str);

    /* */
    memset(str, 0, strlen(str));
    strcpy(str, tmp);
    printf("%s\n", str);

    int test[3];
    printf("%d\n", test[0]);
    printf("%d\n", sizeof(test));

    int *test_p = (int *) malloc(7 * sizeof(int));
    printf("%d\n", test_p[0]);
    /* 指针的sizeof,64位机为8 */
    printf("%d\n", sizeof(test_p));
    //memset(test, 0, sizeof(test) * sizeof(int));
    printf("%d\n", test[0]);
}

int main()
{
    /******************* sizeof 和 strlen , 应用到指针上, 形参上 *****************/
    sizeof_and_strlen();

    /******************** 内存拷贝 ***************************************/
    str_copy();

    /* 运算符优先级 */
    return 0;
}
