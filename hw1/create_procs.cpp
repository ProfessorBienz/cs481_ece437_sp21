#include "create_procs.h"
#include "child_procs.h"

void create_procs()
{
    int rc;
    rc = fork();

    if (rc == 0)
    {
        rc = fork();
        if (rc == 0)
        {
            grandchild();
            exit(1);
        }
        else
        {
            rc = wait(NULL);
            child();
            exit(1);
        }
    }
    else
    {
        rc = wait(NULL);
        parent();
    }
}
