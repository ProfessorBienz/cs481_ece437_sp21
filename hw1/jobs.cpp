#include <stdio.h>
#include <stdlib.h>
#include "scheduler.h"
#include "jobs.h"

int jobcmp(const void* a, const void* b)
{
    Job* job_a = (Job*) a;
    Job* job_b = (Job*) b;

    if (job_a->priority > job_b->priority)
    {
        return 1;
    }
    else if (job_a->priority == job_b->priority && 
            job_a->idx > job_b->idx)
    {
        return 1;
    }
    else return 0;
}


