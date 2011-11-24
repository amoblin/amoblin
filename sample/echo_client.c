#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>

#define SA struct sockaddr

ssize_t readline(int fd, void *vptr, size_t maxlen) {
    ssize_t n, rc;
    char c, *ptr;
    
    ptr = vptr;
    for (n = 1; n < maxlen; n++) {
again:
        if( (rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if( c == '\n') {
                break;
            }
        } else if( rc == 0) {
            *ptr = 0;
            return (n-1);
        } else {
            if( errno == EINTR) {
                goto again;
            }
            return -1;
        }
    }
    *ptr = 0;
    return n;
}

void str_cli(FILE *fp, int sockfd) {
    char sendline[1024], recvline[1024];

    while( fgets(sendline, 1024, fp) != NULL) {
        write(sockfd, sendline, strlen(sendline));

        if( readline(sockfd, recvline, 1024) == 0) {
            printf("%s: server terminated prematurely.\n", __func__);
        }

        fputs(recvline, stdout);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error.\n");
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5001);
    if ( inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) < 0) {
        printf("error!\n");
        exit(0);
    }

    if( connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
        printf("connect error!\n");
        exit(0);
    }

    str_cli(stdin, sockfd);

    return 0;
}
