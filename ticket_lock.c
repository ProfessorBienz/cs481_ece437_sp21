// Portions from Patrick Bridges cs481 slides
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "ticket_lock.h"
#include <sys/wait.h>
#include <sys/time.h>

lock_t mylock;

double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}

void* mythread(void* arg)
{
    int* m = (int*) arg;

    lock(&mylock);
    for (int i = 0; i < 1000000; i++)
        *m += 1;
    unlock(&mylock);

    return (void*) m;
}

int main(int argc, char* argv[])
{
    int rc;
    volatile int m = 0;
    int* ret_m;
    int n = 100;

    lock_init(&mylock);

    double t0 = get_time();
    pthread_t* threads = (pthread_t*)malloc(n*sizeof(pthread_t));
    for (int i = 0; i < n; i++)
        rc = pthread_create(&(threads[i]), NULL, mythread, (void*)&m);

    for (int i = 0; i < n; i++)
        pthread_join(threads[i], (void**)&ret_m);
    double tfinal = get_time() - t0;

    printf("M : %d  Ret : %d, Time : %e\n", m, *ret_m, tfinal);
}
