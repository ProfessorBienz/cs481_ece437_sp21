#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}

void Spin(int n_sec)
{
    double t0 = get_time();

    while (get_time() - t0 < n_sec)
    {
    }
}


int main (int argc, char* argv[])
{
    int* p = malloc(sizeof(int));

    assert(p != NULL);
    printf("(%d) address of p: %08x\n", getpid(), (unsigned int) p);

    *p = 0;
    while (1)
    {
        Spin(1);
	*p = *p + 1;
	printf("(%d) p: %d\n", getpid(), *p);
    }

    return 0;
}
