#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc < 0)
    {
        printf("Fork Failed!\n");
        return 1;
    }
    else if (rc == 0)
    {
        close(STDOUT_FILENO);
        open("./redirect_ex.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("exec_ex.c");
        myargs[2] = NULL;
        execvp(myargs[0], myargs);
    }
    else
    {
        int wc = wait(NULL);
    }

    return 0;
}
