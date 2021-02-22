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
    if (add_ctr == -1)
        add_ctr = counter++;
}

void mult(int time)
{
    if (mult_ctr == -1)
        mult_ctr = counter++;
}

void reset(int time)
{
    if (reset_ctr == -1)
        reset_ctr = counter++;
}

void divide(int time)
{
    if (divide_ctr == -1)
        divide_ctr = counter++;
}

void subtract(int time)
{
    if (subtract_ctr == -1)
        subtract_ctr = counter++;
}

void test(int* n_jobs, Job** jobs)
{
    *n_jobs = 5;

    Job* example_jobs = (Job*)malloc((*n_jobs)*sizeof(Job));
    int priority[5] = {1,1,1,1,1};
    int time[5] = {3,2,4,3,1};
    Operation ops[5] = {add, subtract, divide, reset, mult};
    for (int i = 0; i < *n_jobs; i++)
    {
        example_jobs[i].idx = i;
        example_jobs[i].priority = priority[i];
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


TEST(SchedulerTest, TestsIntests)
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
    ASSERT_EQ(add_ctr, 0);
    ASSERT_EQ(mult_ctr, 4);
    ASSERT_EQ(reset_ctr, 3);
    ASSERT_EQ(divide_ctr, 2);
    ASSERT_EQ(subtract_ctr, 1);
    free(jobs);
}
