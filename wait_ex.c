#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
        exit(1);
    }
    else
    {
        int wc = wait(NULL);
        printf("Hello, I am the parent of %d (pid: %d)\n", wc, (int) getpid());
    }

    return 0;
}
