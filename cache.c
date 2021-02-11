#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}

int main(int argc, char* argv[])
{
    int n = 1000000000;
    int n_cache = 1000;
    int n_iter = n / n_cache;

    volatile int counter = 0;
    double t0, tfinal;


    // Time to access data from cache
    int* cache = (int*)malloc(n_cache*sizeof(int));
    for (int i = 0; i < n_cache; i++)
        counter += cache[i];
    t0 = get_time();
    for (int i = 0; i < n_iter; i++)
    {
        for (int j = 0; j < n_cache; j++)
        {
            counter += cache[j];
        }
    }
    tfinal = (get_time() - t0) / n;
    printf("Cache Time : %e\n", tfinal);
    free(cache);


    // Time to access data from main memory
    int* main_mem = (int*)malloc(n*sizeof(int));
    t0 = get_time();
    for (int i = 0; i < n; i++)
    {
        counter += main_mem[i];
    }
    tfinal = (get_time() - t0) / n;
    printf("Main Mem Time : %e\n", tfinal);
    free(main_mem);

    return 0;
}
