// Parts taken from Patrick Bridges cs481 slides

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <sys/types.h>
#include <unistd.h>

// Get time of day (time in seconds, precision to nanoseconds)
double get_time()
{
    struct timeval timecheck;
    gettimeofday(&timecheck, NULL);
    return (double)timecheck.tv_sec + (double)timecheck.tv_usec*1e-6;
}

// Spin for n_sec seconds
void Spin(int n_sec)
{
    double t0 = get_time();

    while (get_time() - t0 < n_sec)
    {
    }
}



// Main method 
int main (int argc, char* argv[])
{
    // Allocate a single integer (hold a pointer to it)
    int* p = malloc(sizeof(int));

    // Make sure p is not NULL (program would crash)
    assert(p != NULL);

    // Print the process id (unique identifier per process) 
    // Also print address at which integer p is allocated
    printf("(%d) address of p: %08x\n", getpid(), (unsigned int) p);

    // Initialize value of p to 0
    *p = 0;

    int i;
    for (int i = 0; i < 10; i++)
    {
        // Spin for 1 second
        Spin(1);

	// Add one to value of p
	*p = *p + 1;

	// Print current value of p for my process 
	printf("(%d) p: %d\n", getpid(), *p);
    }

    // Clean up
    free(p);

    return 0;
}
