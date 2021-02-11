#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("Need command line arg\n");
        return 1;
    }

    int n = atoi(argv[1]);
    int* array = (int*)malloc(100*sizeof(int));
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        counter += array[i];
    }
    free(array);

    return 0;
}
