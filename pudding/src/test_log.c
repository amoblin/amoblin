#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>

int main( int argc, char* argv[] )
{
    int logfd = open( "log", O_RDWR | O_CREAT | O_APPEND, 0644 );
    close(STDERR_FILENO);
    dup2(logfd, STDERR_FILENO);
    close(logfd);
    openlog(NULL, LOG_PERROR, LOG_DAEMON);
    syslog(LOG_DEBUG, "%i\n", time(NULL));
    return 0;
}
