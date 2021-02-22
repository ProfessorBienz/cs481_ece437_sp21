// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "jobs.h"
#include "scheduler.h"

int add_ctr;
int mult_ctr;
int reset_ctr;
int divide_ctr;
int subtract_ctr;
int counter;

void add(int time)
{
    add_ctr = counter++;
}

void mult(int time)
{
    mult_ctr = counter++;
}

void reset(int time)
{
    reset_ctr = counter++;
}

void divide(int time)
{
    divide_ctr = counter++;
}

void subtract(int time)
{
    subtract_ctr = counter++;
}

void test(int* n_jobs, Job** jobs)
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


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}


TEST(SchedulerTesto, TestsIntests)
{
    int n_jobs;
    Job* jobs;
    int time_slice = 1;
    
    test(&n_jobs, &jobs);
    counter = 0;
    add_ctr = -1;
    mult_ctr = -1;
    reset_ctr = -1;
    divide_ctr = -1;
    subtract_ctr = -1;
    priority_rr(n_jobs, jobs, time_slice);
    ASSERT_EQ(add_ctr, 3);
    ASSERT_GT(mult_ctr, 6);
    ASSERT_GT(reset_ctr, 6);
    ASSERT_GT(divide_ctr, 6);
    ASSERT_EQ(subtract_ctr, 1);
    free(jobs);
}

