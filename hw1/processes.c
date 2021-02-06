#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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
    int counter = 0;
    int rc = fork();
    if (rc == 0) // Child Process
    {
        child();
    }
    else // Parent Process
    {
        int wc = wait(NULL);
        parent();
    }

}
