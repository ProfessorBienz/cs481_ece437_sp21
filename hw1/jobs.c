#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scheduler.h"
#include "jobs.h"

int counter = 0;

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

int job0(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter += 3;
    }
}

int job1(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter *= 2;
    }
}

int job2(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter = 1;
    }
}

void create_jobs(int* n_jobs, Job** jobs)
{
    *n_jobs = 3;

    Job* example_jobs = (Job*)malloc((*n_jobs)*sizeof(Job));
    example_jobs[0].priority = 1;
    example_jobs[0].idx = 0;
    example_jobs[0].time = 2;
    example_jobs[0].run_job = job0;

    example_jobs[1].priority = 1;
    example_jobs[1].idx = 1;
    example_jobs[1].time = 1;
    example_jobs[1].run_job = job1;

    example_jobs[2].priority = 0;
    example_jobs[2].idx = 2;
    example_jobs[2].time = 3;
    example_jobs[2].run_job = job2;

    *jobs = example_jobs;
}

int main(int argc, char* argv[])
{
    int n_jobs;
    Job* jobs;
    create_jobs(&n_jobs, &jobs);
    counter = 0;
    priority(n_jobs, jobs);
    assert(counter == 14);
    free(jobs);

    create_jobs(&n_jobs, &jobs);
    counter = 0;
    int time_slice = 1;
    priority_rr(n_jobs, jobs, time_slice);
    assert(counter == 11);
    free(jobs);
}

