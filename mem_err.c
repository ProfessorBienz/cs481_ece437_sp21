#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void no_malloc()
{
    int* mem;
    printf("mem[0] = %d\n", mem[0]);
}

void no_free()
{
    int* mem = (int*)malloc(100*sizeof(int));
    printf("mem[0] = %d\n", mem[0]);
}

void double_free()
{
    int* mem = (int*)malloc(100*sizeof(int));
    printf("mem[0] = %d\n", mem[0]);
    free(mem);
    free(mem);
}

void access_after_free()
{
    int* mem = (int*)malloc(100*sizeof(int));
    free(mem);
    printf("mem[0] = %d\n", mem[0]);
}

void access_unallocated(int n)
{
    int* mem = (int*)malloc(n*sizeof(int));
    int* cpy_mem = (int*)malloc(10*sizeof(int));
    memcpy(mem, cpy_mem, n*sizeof(int));
    free(mem);
    free(cpy_mem);
}

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        printf("Need command line arg\n");
        return 1;
    }

    int mem_issue = atoi(argv[1]);
    switch(mem_issue)
    {
        case 0:
            no_malloc();
            break;
        case 1:
            no_free();
            break;
        case 2:
            double_free();
            break;
        case 3:
            access_after_free();
            break;
        case 4:
            if (argc == 2)
            {
                printf("Need command line int n\n");
                return 1;
            }
            int n = atoi(argv[2]);
            access_unallocated(n);
            break;
        default:
            break;
    }

    return 0;
}
