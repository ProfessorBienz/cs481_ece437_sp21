#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    printf("hello world (pid: %d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0)
    {
        printf("Fork Failed!\n");
        return 1;
    }
    else if (rc == 0)
    {
        printf("Hello, I am child (pid: %d)\n", (int) getpid());
        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("exec_ex.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
        printf("We should never get here...\n");
    }
    else
    {
        int wc = wait(NULL);
        printf("Hello, I am the parent of %d (pid: %d)\n", rc, (int) getpid());
    }

    return 0;
}
