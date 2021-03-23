// Portions from Patrick Bridges cs481 slides
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* mythread(void* arg)
{
    int m = (int) arg;
    return (void*) m + 1;
}

int main(int argc, char* argv[])
{
    int rc;
    int m = 5;
    int ret_m;
    int n = 100;

    pthread_t* threads = (pthread_t*)malloc(n*sizeof(pthread_t));
    for (int i = 0; i < n; i++)
        rc = pthread_create(&(threads[i]), NULL, mythread, (void*)m);

    for (int i = 0; i < n; i++)
        pthread_join(threads[i], (void**)&ret_m);

    printf("M : %d  Ret : %d\n", m, ret_m);
}
