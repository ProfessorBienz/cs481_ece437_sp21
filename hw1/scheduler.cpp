#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"
#include "scheduler.h"

void priority(int n_jobs, Job* jobs)
{
    qsort(jobs, n_jobs, sizeof(Job), jobcmp);
    for (int i = 0; i < n_jobs; i++)
    {
        jobs[i].run_job(jobs[i].time);
    }
}

void priority_rr(int n_jobs, Job* jobs, int time_slice)
{
    qsort(jobs, n_jobs, sizeof(Job), jobcmp);
    int p;
    int idx = 0;
    int init_idx = 0;
    int time = 0;
    while (idx < n_jobs)
    {
        time = jobs[idx].time;
        p = jobs[idx++].priority;
        while (idx < n_jobs && jobs[idx].priority == p)
        {
            time += jobs[idx].time;
            idx++;
        }
        while (time > 0)
        {
            for (int i = init_idx; i < idx; i++)
            {
                int t = time_slice;
                if (t > jobs[i].time)
                    t = jobs[i].time;
                jobs[i].run_job(t);
                jobs[i].time -= t;
                time -= t;
            }
        }

        init_idx = idx;
    }
}


