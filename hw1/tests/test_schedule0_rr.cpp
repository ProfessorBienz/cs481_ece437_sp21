// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "jobs.h"
#include "scheduler.h"

int counter = 0;

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
    int n_jobs, time_slice;
    Job* jobs;

    test(&n_jobs, &jobs);
    counter = 0;
    time_slice = 1;
    priority_rr(n_jobs, jobs, time_slice);
    ASSERT_EQ(counter, 15);
    free(jobs);
}
