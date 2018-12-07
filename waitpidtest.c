#include "types.h"
#include "stat.h"
#include "user.h"

int
main (int argc, char* argv[])
{
    printf(0, "hello world (pid:%d)\n", (int) getpid());
    int status;
    int rc = fork();
    if (rc < 0) {
        exit(1);
    } else if (rc == 0) {
        printf(0, "Hello, I am child (pid:%d)\n", (int) getpid());
        exit(0);
    } else {
        int wc = waitpid(rc, &status, 0);
        printf(0, "hello, I am parent of %d (wc:%d) (pid:%d)\nChild exited with status %d\n",
                rc, wc, (int) getpid(), status);
        exit(0);
    }

    return 0;
}
