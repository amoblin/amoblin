#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>

#define SA struct sockaddr

void str_echo(int sockfd) {
    ssize_t n;
    char buf[1024];
again:
    while ( (n = read(sockfd, buf, 1024)) > 0) {
        write(sockfd, buf, n);
    }

    if( n<0 && errno == EINTR) {
        goto again;
    } else if (n < 0) {
        printf("%s: read error.\n", __func__);
    }
}

int main() {
    int listenfd, connfd;
    pid_t childpid;
    struct sockaddr_in cliaddr, servaddr;

    if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error!\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(5001);

    if( bind(listenfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
        perror("bind error!\n");
        exit(1);
    }

    if( listen(listenfd, 5) < 0 ) {
        printf("listen error.\n");
        exit(1);
    }

    for(;;) {
        if ( (connfd = accept( listenfd, (SA *) NULL, NULL)) < 0 ) {
            printf("connect error.\n");
            exit(0);
        }

        if( (childpid = fork()) == 0) {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);
    }
    close(connfd);
}
