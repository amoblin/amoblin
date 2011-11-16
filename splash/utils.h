#ifndef utils_h
#define utils_h
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


/********************************************
 * 系统日志
 *
 * ******************************************/
#include <syslog.h>
#include <unistd.h>
#include <fcntl.h>
void log_init(char *log_name) {
    /* 记录日志 */
    int logfd = open(log_name, O_RDWR | O_CREAT | O_APPEND, 0644 );
    close(STDERR_FILENO);
    dup2(logfd, STDERR_FILENO);
    close(logfd);
    openlog(NULL, LOG_PERROR, LOG_DAEMON);
}

void log_test() {
    log_init("test.log");
    syslog(LOG_INFO, "%d: %s", 10, "hello");
    syslog(LOG_ERR, "%d: %s", 12, "world");
}
#endif
