#ifndef JOBS_H
#define JOBS_H

#include <stdio.h>
#include <stdlib.h>

typedef int (*Operation)();
typedef struct job
{
    int idx;
    int time;
    int priority;
    Operation run_job;
} Job;

int jobcmp(const void* a, const void* b);
int job0(int time);
int job1(int time);
int job2(int time);
void create_jobs(int* n_jobs, Job** jobs);

#endif
