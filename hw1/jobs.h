#ifndef JOBS_H
#define JOBS_H

#include <stdio.h>
#include <stdlib.h>

typedef void (*Operation)(int);
typedef struct job
{
    int idx;
    int time;
    int priority;
    Operation run_job;
} Job;

int jobcmp(const void* a, const void* b);
void create_jobs(int* n_jobs, Job** jobs);

#endif
