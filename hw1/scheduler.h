#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdio.h>
#include <stdlib.h>
#include "jobs.h"

void priority(int n_jobs, Job* jobs);
void priority_rr(int n_jobs, Job* jobs, int time_slice);

#endif
