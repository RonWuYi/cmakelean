#include "gtest/gtest.h"
#include "Formula.h"

TEST(blaTest, test1) {
    //assert
    EXPECT_EQ(Formula::bla (0),  0);
    EXPECT_EQ(Formula::bla (10), 20);
    EXPECT_EQ(Formula::bla (50), 100);
}

TEST(MaximumSubarray53, test2) {
    std::vector<int> v {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    EXPECT_EQ(EasySolution::maxSubArray (v),  6);
}

TEST(duplicateZeros, test3)
{
    std::vector<int> v1 {1, 0, 2, 3, 0, 4, 5, 0};
    std::vector<int> v2 {1, 0, 0, 2, 3, 0, 0, 4};
    SolutionduplicateZeros::duplicateZeros(v1);
    EXPECT_EQ(v1, v2);
}