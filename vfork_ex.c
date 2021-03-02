#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>

// Get time of day (time in seconds, precision to nanoseconds)
double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}



int main(int argc, char* argv[])
{
    double t0, tfinal;
    int rc;

    t0 = get_time();
    rc = vfork();
    if (rc == 0)
    {
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
    tfinal = get_time() - t0;
    printf("VFork example : %e\n", tfinal);


    t0 = get_time();
    rc = fork();
    if (rc == 0)
    {
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
    tfinal = get_time() - t0;
    printf("Fork example : %e\n", tfinal);



    return 0;
}
