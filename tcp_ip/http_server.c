#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* strlen() defns here. */
#include <string.h>

#include <time.h>

#include <netinet/in.h>

#include <fcntl.h>

#define MAXLINE 1024

#define SA struct sockaddr

void writen(int connfd) {
    time_t ticks;
    char buff[MAXLINE];

    ticks = time(NULL);

    char content[] = "<html>\n \
                      <head>\n \
                      <title>index page</title>\n\
                      </head>\n\
                      <body>现在时间<h1>\n ";

    char html[MAXLINE];
    snprintf(html, sizeof(html), "%s%.24s</h1>\n</body>\n</html>", content, ctime(&ticks));

    char head[] = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: ";

    snprintf( buff,sizeof(buff), "%s%d\r\n\r\n%s", head, strlen(html), html);
    if( write(connfd, buff, strlen(buff)) < 0) {
        printf("write error!\n");
    }

    sleep(10);
}

int main() {

    int retval;
    int pid;

    /* 监听描述符 */
    int listenfd;

    /* 连接描述符 */
    int connfd;
    struct sockaddr_in servaddr;

    /* 准备监听描述符的第1步 */
    /* 注意： < 优先级比 = 高，所以千万不要忘了括号！ */
    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error!\n");
        exit(0);
    }

    /* 准备监听描述符的第2步 */

    /* 设置服务器地址 */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(80);

    if( bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0 ) {
        perror("bind error!\n");
        exit(1);
    }

    /* 准备监听描述符的第3步 */
    if( listen(listenfd, 5) < 0 ) {
        printf("listen error.\n");
        exit(1);
    }

    for(;;) {
        connfd = accept( listenfd, (SA *) NULL, NULL);
        if( connfd < 0 ) {
        }

        pid = fork();
        if( pid < 0 ) {
            printf("error!\n");
        }

        retval = fcntl(connfd, F_GETFL, 0);
        if( retval < 0) {
            return 0;
        }
        fcntl(connfd, F_SETFL, retval | O_NONBLOCK);

        if( pid  == 0) {
            close(listenfd);
            writen(connfd);
            close(connfd);
            exit(0);
        }
        close(connfd);
    }
    close(listenfd);
    return 0;
}
