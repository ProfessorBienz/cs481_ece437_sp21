#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // Address of instructions (point to code)
    printf("location of instructions : %p\n", (void*) main);

    // Address of heap (malloc address)
    int size = 1;
    double* c = (double*)malloc(size*sizeof(double));
    printf("location of heap : %p\n", (void*) c);
    free(c);

    // Address of stack
    int x = 3;
    printf("location of stack : %p\n", (void*) &x);

    return 0;
}
