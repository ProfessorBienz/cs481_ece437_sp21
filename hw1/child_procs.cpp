#include "child_procs.h"

FILE* fn;

void grandchild()
{
    fprintf(fn, "Grandchild\n");
}

void child()
{
    fprintf(fn, "Child\n");
}

void parent()
{
    fprintf(fn, "Parent\n");
}

void open_to_write()
{
    fn = fopen("./procs.output", "w");
}

void open_to_read()
{
    fn = fopen("./procs.output", "r");
}

void close_file()
{
    fclose(fn);
}

int read_word(char* buff)
{
    return fscanf(fn, "%s\n", buff);
}

