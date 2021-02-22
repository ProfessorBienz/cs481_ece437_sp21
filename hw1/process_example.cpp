#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int counter = 0;

void child()
{
    counter += 7;
}

void parent()
{
    counter *= 2;
}

int main(int argc, char* argv[])
{
    int rc = fork();
    if (rc == 0) // Child Process
    {
        child();
        printf("CHILD: Counter : %d, Address : %p\n", counter, (void*)&counter);
    }
    else // Parent Process
    {
        rc = wait(NULL);
        parent();
        printf("PARENT: Counter : %d, Address : %p\n", counter, (void*)&counter);
    }

    return 0;
}

