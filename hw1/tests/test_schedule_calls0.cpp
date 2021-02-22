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

void add(int time)
{
    add_ctr = 1;
}

void mult(int time)
{
    mult_ctr = 1;
}

void reset(int time)
{
    reset_ctr = 1;
}

void test(int* n_jobs, Job** jobs)
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

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}


TEST(SchedulerTest, TestsIntests)
{
    int n_jobs;
    Job* jobs;
    
    test(&n_jobs, &jobs);
    add_ctr = 0;
    mult_ctr = 0;
    reset_ctr = 0;
    priority(n_jobs, jobs);
    ASSERT_EQ(add_ctr, 1);
    ASSERT_EQ(mult_ctr, 1);
    ASSERT_EQ(reset_ctr, 1);
    free(jobs);
}
