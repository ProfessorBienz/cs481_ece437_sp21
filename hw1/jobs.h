#ifndef JOBS_H
#define JOBS_H

#include <stdio.h>
#include <stdlib.h>

typedef void (*Operation)();
typedef struct job
{
    int idx;
    int time;
    int priority;
    Operation run_job;
} Job;

int jobcmp(const void* a, const void* b);
void job0(int time);
void job1(int time);
void job2(int time);
void create_jobs(int* n_jobs, Job** jobs);

#endif
