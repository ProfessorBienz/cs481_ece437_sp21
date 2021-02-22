// EXPECT_EQ and ASSERT_EQ are macros
// EXPECT_EQ test execution and continues even if there is a failure
// ASSERT_EQ test execution and aborts if there is a failure
// The ASSERT_* variants abort the program execution if an assertion fails 
// while EXPECT_* variants continue with the run.

#include "gtest/gtest.h"
#include "create_procs.h"
#include "child_procs.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}


TEST(GrandchildTest, TestsIntests)
{
    open_to_write();
    create_procs();
    close_file();

    const char* p = "Parent";

    open_to_read();
    char buff[255];
    bool read_p = false;
    int n_items;

    n_items = read_word(buff);
    if (n_items != EOF && buff[0] == 'P')
    {
        for (int i = 0; i < 6; i++)
            ASSERT_EQ(buff[i], p[i]);
        read_p = true;
    }

    n_items = read_word(buff);
    if (n_items != EOF && buff[0] == 'P' && read_p == false)
    {
        for (int i = 0; i < 6; i++)
            ASSERT_EQ(buff[i], p[i]);
        read_p = true;       
    }

    n_items = read_word(buff);
    if (n_items != EOF && buff[0] == 'P' && read_p == false)
    {
        for (int i = 0; i < 6; i++)
            ASSERT_EQ(buff[i], p[i]);
        read_p = true;       
    }

    ASSERT_EQ(read_p, true);

    close_file();
}
