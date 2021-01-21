// Portions from Patrick Bridges cs481 slides
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global variables
// Volatile so that loop is not optimized by compiler
volatile int counter = 0;
int loops;


// Pthread routine -- after pthread is started, it will execute this method
void* worker(void* arg)
{
    // Loop 'loops' times, incrementing counter each iteration
    int i;
    for (i = 0; i < loops; i++)
    {
	counter++;
    }
    return NULL;
}


// Main method
int main(int argc, char* argv[])
{
    // Need command line argument... if none, return error
    if (argc != 2)
    {
	printf("Need Command Line Arg\n");
	exit(1);
    }

    // Read number of loops from command line
    loops = atoi(argv[1]);

    // Print initial value of counter (0)
    printf("Initial value : %d\n", counter);

    // Create two threads
    pthread_t p1, p2;
    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);

    // Have each thread execute 'worker' routine
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    // Print final value of counter (should be 2*loops)
    printf("Final value : %d\n", counter);
}
