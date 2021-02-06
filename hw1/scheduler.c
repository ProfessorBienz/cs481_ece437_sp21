#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"
#include "scheduler.h"

// Priority Scheduling -- Jobs with highest priority (lowest number) run first
//   -- If two jobs with same priority, lower index runs first
void priority(int n_jobs, Job* jobs)
{
}

// Priority Scheduling with Round Robin -- Jobs with highest priority (lowest number)
//    run first
//    -- If two jobs have same priority, run both in round robin 
//    -- Time slice for round robin passed as a parameter
void priority_rr(int n_jobs, Job* jobs, int time_slice)
{
}


