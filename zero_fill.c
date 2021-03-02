#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
    int n = atoi(argv[1]);

    double* data = (double*)malloc(n*sizeof(double));
    for (int i = 0; i < n; i++)
    {
        data[i] = i;
    }
    free(data);

    data = (double*)malloc(n*sizeof(double));
    for (int i = 0; i < n; i++)
    {
        printf("Data[%d] = %e\n", i, data[i]);
    }
    free(data);




    return 0;
}
