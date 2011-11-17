#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

#include <pthread.h>
void thread_test() {
}

