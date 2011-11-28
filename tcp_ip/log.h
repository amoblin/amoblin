
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

