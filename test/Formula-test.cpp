#include "gtest/gtest.h"
#include "Formula.h"
#include "header.h"

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

TEST(areNumbersAscending, test6)
{
    SolutionareNumbersAscending temp{};
    EXPECT_EQ(temp.areNumbersAscending("hello world 5 x 5"), false);
}

TEST(myPow, test7)
{
    SolutionmyPow p{};
    EXPECT_EQ(p.myPow02(2.00000, 10), 1024.00000);
    EXPECT_EQ(p.myPow02(2.00000, -2), 0.25000);
}

TEST(SolutionlengthOfLongestSubstring, test8)
{
    SolutionlengthOfLongestSubstring s{};
    std::string s1{"abcabcbb"};
    std::string s2{"dvdf"};
    std::string s3{"anviaj"};
    std::string s4{"asjrgapa"};
    EXPECT_EQ(s.lengthOfLongestSubstring(s1), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring(s2), 3);
    EXPECT_EQ(s.lengthOfLongestSubstring(s3), 5);
    EXPECT_EQ(s.lengthOfLongestSubstring(s4), 6);
}

TEST(SolutionisRobotBounded, test9)
{
    SolutionisRobotBounded s{};
    EXPECT_EQ(s.isRobtBounded("GG"), false);
    EXPECT_EQ(s.isRobtBounded("GGLLGG"), true);
    EXPECT_EQ(s.isRobtBounded("GGRRGG"), true);
    EXPECT_EQ(s.isRobtBounded("GL"), true);
    EXPECT_EQ(s.isRobtBounded("GR"), true);
}

TEST(SolutionfindDuplicate, test10)
{
    SolutionfindDuplicate s{};
    std::vector<int> v1{1,3,4,2,2};
    std::vector<int> v2{3,1,3,4,2};
    EXPECT_EQ(s.findDuplicate(v1), 2);
    EXPECT_EQ(s.findDuplicate(v2), 3);    
    EXPECT_EQ(s.findDuplicate02(v1), 2);
    EXPECT_EQ(s.findDuplicate02(v2), 3);
    EXPECT_EQ(s.findDuplicate03(v1), 2);
    EXPECT_EQ(s.findDuplicate03(v2), 3);
}

TEST(SolutionlongestPalindrome, test11)
{
    SolutionlongestPalindrome s{};
    std::string str{"abccccdd"};
    EXPECT_EQ(s.longestPalindrome02(str), 7);
}

TEST(SolutionrunningSum, test12)
{
    SolutionrunningSum s{};
    std::vector<int> v1{1,2,3,4};
    std::vector<int> v2{1,3,6,10};
    EXPECT_EQ(s.runningSum01(v1), v2);
    // EXPECT_EQ(s.runningSum02(v1), v2);
}

TEST(SolutionclimbStairs, test12)
{
    SolutionclimbStairs s{};
    EXPECT_EQ(s.climbStairs02(2), 2);
    EXPECT_EQ(s.climbStairs02(1), 1);    
    EXPECT_EQ(s.climbStairs02(10), 89);
    EXPECT_EQ(s.climbStairs03(2), 2);
    EXPECT_EQ(s.climbStairs03(1), 1);    
    EXPECT_EQ(s.climbStairs03(10), 89);
}

TEST(SolutionmaxArea, test12)
{
    SolutionmaxArea s{};
    std::vector<int> v1{1,8,6,2,5,4,8,3,7};
    EXPECT_EQ(s.maxArea(v1), 49);
}

TEST(SolutionwallsAndGatesNew, test12)
{
    SolutionwallsAndGatesNew s{};
    std::vector<std::vector<int>> v1{{2147483647,-1,0,2147483647},{2147483647,2147483647,2147483647,-1},
        {2147483647,-1,2147483647,-1},{0,-1,2147483647,2147483647}};
    std::vector<std::vector<int>> vresult{{3,-1,0,1},{2,2,1,-1},{1,-1,2,-1},{0,-1,3,4}};
    s.wallsAndGates(v1);
    EXPECT_EQ(v1, vresult);
}

TEST(SolutiondecodeString, test12)
{
    SolutiondecodeString s{};
    std::string str1{"3[a]2[bc]"};
    std::string str2{"3[a2[c]]"};
    std::string str3{"2[abc]3[cd]ef"};
    EXPECT_EQ(s.decodeString(str1), "aaabcbc");
    EXPECT_EQ(s.decodeString(str2), "accaccacc");
    EXPECT_EQ(s.decodeString(str3), "abcabccdcdcdef");
}

// TEST(SolutiondailyTemperatures, test12)
// {
//     SolutiondailyTemperatures s{};
//     std::vector<int> v1{55,38,53,81,61,93,97,32,43,78};
//     std::vector<int> v2{73,74,75,71,69,72,76,73};
//     std::vector<int> result1{3,1,1,2,1,1,0,1,1,0};
//     std::vector<int> result2{1,1,4,2,1,1,0,0};
//     EXPECT_EQ(s.dailyTemperatures(v1), result1); 
//     EXPECT_EQ(s.dailyTemperatures(v2), result2); 
// }