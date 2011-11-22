#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

/* 多进程 */
void fork_test() {
    pid_t fpid;
    int count = 0;

    fpid = fork();
    if(fpid < 0) {
        printf("error in fork!");
        exit(0);
    }

    while(1) {
        if(fpid == 0) {
            printf("child process, pid is %d\n", getpid());
            count++;
            sleep(1);
        } else {
            printf("parent process, pid is %d\n", getpid());
            count++;
            sleep(1);
        }
    }
    printf("count is %d\n", count);
    int exitcode = 0;
    pid_t re = waitpid(fpid, &exitcode, 0);
}

/* 匿名管道的使用 */
void pipe_test() {
    pid_t fpid;
    int fds[2];
    int ret;
    char buf[MAX_LINE + 1];
    char *test_str = "hello, 世界！";
    if ( pipe(fds) != 0 ) {
        exit(0);
    }

    fpid = fork();
    if(fpid < 0) {
        printf("error in fork!");
        exit(0);
    }

    while(1) {
        if( fpid == 0) {
            /* 管道无内容则挂起 */
            ret = read( fds[0], buf, MAX_LINE);
            buf[ret] = 0;
            printf("child read:\n%s\n", buf);
        } else {
            ret = write( fds[1], test_str, strlen(test_str));
            sleep(3);
        }
    }
}

/* 多线程 */
#include <pthread.h>
void thread_test() {
    pthread_t pid;
    //pthread_create(&pid, );
}


/* 加载动态链接库 */
#include <dlfcn.h>
int dll_test() {
    void *handle;
    int (*cosine)(int);
    char *error;

    /* 加载 */
    handle = dlopen("./libtest.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    dlerror();    /* Clear any existing error */

    /* Writing: cosine = (double (*)(double)) dlsym(handle, "cos");
       would seem more natural, but the C99 standard leaves
       casting from "void *" to a function pointer undefined.
       The assignment used below is the POSIX.1-2003 (Technical
       Corrigendum 1) workaround; see the Rationale for the
       POSIX specification of dlsym(). */

    *(void **) (&cosine) = dlsym(handle, "rise");

    if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*cosine)(99));
    dlclose(handle);
    exit(EXIT_SUCCESS);
}
