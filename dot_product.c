#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/time.h>

double* a;
double* b;
int n, N;
double total_sum;


double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}

void* dot_product(void* arg)
{
    int* start = (int*)arg;

    double* sum = (double*)malloc(sizeof(double));
    *sum = 0;
    for (int i = *start; i < (*start)+n; i++)
        *sum += a[i] * b[i];

    return (void*)sum;
}

int main(int argc, char* argv[])
{
    int num_threads = atoi(argv[1]);
    pthread_t* threads = (pthread_t*)malloc(num_threads*sizeof(pthread_t));
    
    N = 10000;
    n = N / num_threads;
    a = (double*)malloc(N*sizeof(double));
    b = (double*)malloc(N*sizeof(double));

    total_sum = 0;

    for (int i = 0; i < N; i++)
    {
        a[i] = 1.0;
        b[i] = 1.0 / (i+1);
    }

    int* starts = (int*)malloc(num_threads*sizeof(int));
    for (int i = 0; i < num_threads; i++)
    {
        starts[i] = n*i;
        pthread_create(&(threads[i]), NULL, dot_product, (void*)&(starts[i]));
    }

    double* sum_ptr;
    for (int i = 0; i < num_threads; i++)
    {
        pthread_join(threads[i], (void**)&sum_ptr);
        total_sum += *sum_ptr;
        free(sum_ptr);
    }

    printf("Total sum %e\n", total_sum);

    free(a);
    free(b);
    free(threads);
    return 0;
}
