#include <stdio.h>

/* exit() defns here */
#include <stdlib.h>

#include <sys/socket.h>

/* sockaddr_in defns here. */
#include <netinet/in.h>

/* bzero() defns here. */
#include <strings.h>

#define MAXLINE 4096


#define SA struct sockaddr

void main(int argc, char **argv) {
    int sockfd;
    int n;
    char recvline[MAXLINE + 1];

    /* ipv4套接字地址结构 */
    struct sockaddr_in servaddr;


    /* Setp 1: */
    if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error\n");
    }

    /* berkeley sytle. memset() */
    bzero(&servaddr, sizeof(struct sockaddr_in));

    servaddr.sin_family = AF_INET;
    /* htons: host to network short int. 13*/
    servaddr.sin_port = htons(80);

    /* inet_aton, inet_addr, inet_ntoa 在ipv4地址和32位二进制数之间转换 */
    /* inet_pton: present to number. 将ip地址转换成需要的数字，支持ipv6 */
    if( inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", "127.0.0.1");
        exit(0);
    }

    /* 建立与服务器的套接字连接，发起握手 */
    if(connect(sockfd, (SA *) &servaddr, sizeof(struct sockaddr_in)) < 0) {
        printf("connect error.\n");
        exit(0);
    }

    while( (n = read(sockfd, recvline, MAXLINE)) > 0) {
        recvline[n] = 0;
        fputs(recvline, stdout);
        if(fputs(recvline, stdout) == EOF) {
            printf("fputs error.\n");
        }
    }

    if(n < 0) {
        printf("read error.\n");
        exit(0);
    }
    exit(0);
}
