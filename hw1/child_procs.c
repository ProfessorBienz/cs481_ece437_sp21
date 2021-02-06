#include "child_procs.h"

FILE* fn;

int grandchild()
{
    fprintf(fn, "Grandchild\n");
}

int child()
{
    fprintf(fn, "Child\n");
}

int parent()
{
    fprintf(fn, "Parent\n");
}

int main(int argc, char* argv[])
{
    fn = fopen("./procs.output", "w");
    create_procs();

    const char* gc = "Grandchild";
    const char* c = "Child";
    const char* p = "Parent";

    fclose(fn);
    fn = fopen("./procs.output", "r");

    char buff[255];
    fscanf(fn, "%s", buff);
    for (int i = 0; i < 10; i++)
        assert(buff[i] == gc[i]);
    fscanf(fn, "%s", buff);
    for (int i = 0; i < 5; i++)
        assert(buff[i] == c[i]);
    fscanf(fn, "%s", buff);
    for (int i = 0; i < 6; i++)
        assert(buff[i] == p[i]);

    fclose(fn);


    return 0;
}
