// Parts taken from Patrick Bridges cs481 slides

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>

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
    // If no command line argument, return error
    if (argc != 2)
    {
        printf("Need Command Line Arg\n");
	exit(1);
    }

    // Read string from command line
    char* str = argv[1];

    int i;
    for (int i = 0; i < 10; i++)
    {
	// Spin for 1 second
        Spin(1);

	// Print string (command line arg)
	printf("%s\n", str);
    }

    return 0;
}
