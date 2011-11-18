#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* 多进程 */
void fork_test() {
    pid_t fpid;
    int count = 0;
    fpid = fork();
    if(fpid < 0) {
        printf("error in fork!");
    }
    else if(fpid == 0) {
        printf("child process, pid is %d\n", getpid());
        printf("Error!\n");
        count++;
        exit(0);
    } else {
        printf("parent process, pid is %d\n", getpid());
        count++;
    }
    printf("count is %d\n", count);
    int exitcode = 0;
    pid_t re = waitpid(fpid, &exitcode, 0);
}

/* 多线程 */
#include <pthread.h>
void thread_test() {
    pthread_t pid;
    pthread_create(&pid, );
}

