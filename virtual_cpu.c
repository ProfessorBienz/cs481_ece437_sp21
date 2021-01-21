#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

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
    if (argc != 2)
    {
        printf("Need Command Line Arg\n");
	exit(1);
    }

    char* str = argv[1];
    while (1)
    {
        Spin(1);
	printf("%s\n", str);
    }

    return 0;
}
