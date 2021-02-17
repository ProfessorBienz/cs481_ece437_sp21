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

void add(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter += 3;
    }
}

void mult(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter *= 3;
    }
}

void reset(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter = 1;
    }
}

void divide(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter /= 2;
    }
}

void subtract(int time)
{
    for (int t = 0; t < time; t++)
    {
        counter -= 2;
    }
}


void test0(int* n_jobs, Job** jobs)
{
    *n_jobs = 3;

    Job* example_jobs = (Job*)malloc((*n_jobs)*sizeof(Job));
    int priority[3] = {1, 1, 0};
    int time[3] = {2, 1, 3};
    Operation ops[3] = {add, mult, reset};
    for (int i = 0; i < *n_jobs; i++)
    {
        example_jobs[i].idx = i;
        example_jobs[i].priority = priority[i];
        example_jobs[i].time = time[i];
        example_jobs[i].run_job = ops[i];
    }
    *jobs = example_jobs;
}

void test1(int* n_jobs, Job** jobs)
{
    *n_jobs = 5;

    Job* example_jobs = (Job*)malloc((*n_jobs)*sizeof(Job));
    int priority[5] = {0,1,1,1,0};
    int time[5] = {3,2,4,3,1};
    Operation ops[5] = {add, mult, reset, subtract, divide};
    for (int i = 0; i < *n_jobs; i++)
    {
        example_jobs[i].priority = priority[i];
        example_jobs[i].idx = i;
        example_jobs[i].time = time[i];
        example_jobs[i].run_job = ops[i];
    }
    *jobs = example_jobs;
}

int main(int argc, char* argv[])
{
    int n_jobs;
    Job* jobs;
    int time_slice;

    test0(&n_jobs, &jobs);
    counter = 0;
    priority(n_jobs, jobs);
    assert(counter == 21);
    free(jobs);

    test0(&n_jobs, &jobs);
    counter = 0;
    time_slice = 1;
    priority_rr(n_jobs, jobs, time_slice);
    assert(counter == 15);
    free(jobs);

    test1(&n_jobs, &jobs);
    counter = 0;
    priority(n_jobs, jobs);
    assert(counter == -5);
    free(jobs);

    test1(&n_jobs, &jobs);
    counter = 0;
    time_slice = 2;
    priority_rr(n_jobs, jobs, time_slice);
    assert(counter == -1);
    free(jobs);
}

