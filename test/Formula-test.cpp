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
    EXPECT_EQ(EasySolution::maxSubArray(v),  6);
}

TEST(duplicateZeros, test3)
{
    std::vector<int> v1 {1, 0, 2, 3, 0, 4, 5, 0};
    std::vector<int> v2 {1, 0, 0, 2, 3, 0, 0, 4};
    SolutionduplicateZeros::duplicateZeros(v1);
    EXPECT_EQ(v1, v2);
}

TEST(mySqrt, test4) {
    EXPECT_EQ(SolutionmySqrt::mySqrt(8), 2);
    EXPECT_EQ(SolutionmySqrt::mySqrt(0), 0);
    EXPECT_EQ(SolutionmySqrt::mySqrt(1), 1);
    EXPECT_EQ(SolutionmySqrt::mySqrt(9), 3);
}

TEST(searchRange, test5)
{
    std::vector<int> v1 {5,7,7,8,8,10};
    std::vector<int> result{3, 4};
    std::vector<int> result01{-1, -1};
    std::vector<int> empty{};
    EXPECT_EQ(SolutionsearchRange::searchRange(v1, 8), result);
    EXPECT_EQ(SolutionsearchRange::searchRange(v1, 6), result01);
    EXPECT_EQ(SolutionsearchRange::searchRange(empty, 0), result01);
}