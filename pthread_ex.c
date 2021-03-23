// Portions from Patrick Bridges cs481 slides
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct __myarg_t 
{
    int a;
    int b;
} myarg_t;

typedef struct __myret_t
{
    int x;
    int y;
} myret_t;

void *mythread(void* arg)
{
    myarg_t *m = (myarg_t*) arg;
    printf("%d %d\n", m->a, m->b);
    //myret_t *r = malloc(sizeof(myret_t));
    myret_t r;
    //r->x = 1;
    r.x = 1;
    //r->y = 2;
    r.y = 2;
    //return (void*) r;
    return (void*) &r;
}

int main(int argc, char* argv[])
{
    pthread_t p;
    int rc;
    myret_t *m;

    myarg_t args;
    args.a = 10;
    args.b = 20;
    rc = pthread_create(&p, NULL, mythread, &args);
    pthread_join(p, (void**)&m);
    printf("Returned %d %d\n", m->x, m->y);
}
