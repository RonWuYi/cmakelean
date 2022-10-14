#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <string>
#include <type_traits>
#include "Formula.h"
#include "header.h"
#include "components.h"

// using ::testing::Lt;
// using ::testing::MatchesRegex;
// using ::testing::StartsWith;

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
    EXPECT_EQ(s.decodeString02(str1), "aaabcbc");
    EXPECT_EQ(s.decodeString02(str2), "accaccacc");
    EXPECT_EQ(s.decodeString02(str3), "abcabccdcdcdef");

    std::vector<int> v{73,74,75,71,69,72,76,73};
    std::vector<int> r{1,1,4,2,1,1,0,0};
    EXPECT_EQ(s.dailyTemperatures(v), r);
}

TEST(SolutionfloodFill, test12)
{
    SolutionfloodFill s{};
    std::vector<std::vector<int>> v{{1,1,1},{1,1,0},{1,0,1}}; 
    std::vector<std::vector<int>> vr{{2,2,2},{2,2,0},{2,0,1}}; 
    EXPECT_EQ(s.floodFill02(v, 1, 1, 2), vr);
}

TEST(SolutiontwoSum, test12)
{
    SolutiontwoSum s{};
    std::vector<int> v{2, 7, 11, 15}; 
    std::vector<int> r{0, 1}; 
    EXPECT_EQ(s.twoSum01(v, 9), r);
    EXPECT_EQ(s.twoSum02(v, 9), r);
}

TEST(SolutionisPalindrome, test12)
{
    SolutionisPalindrome s{};
    std::string s1{"race a car"};
    std::string s2{"A man, a plan, a canal: Panama"};
    EXPECT_EQ(s.isPalindrome(s1), false);
    EXPECT_EQ(s.isPalindrome(s2), true);
}

TEST(SolutionmyAtoi, test12)
{
    SolutionmyAtoi s{};
    std::string str{"42"};
    std::string str1{"4193 with words"};

    // "words and 987"

    std::string str2{"words and 987"};
    EXPECT_EQ(s.myAtoi(str), 42);
    EXPECT_EQ(s.myAtoi(str1), 4193);
    EXPECT_EQ(s.myAtoi(str2), 987);    
    
    EXPECT_EQ(s.myAtoi02(str), 42);
    EXPECT_EQ(s.myAtoi02(str1), 4193);
    EXPECT_EQ(s.myAtoi02(str2), 0);
}

TEST(SolutionfindMissingRanges, test12)
{
    SolutionfindMissingRanges s{};
    std::vector<int> v{0,1,3,50,75};
    int lower = 0;
    int upper = 99;
    std::vector<string> result{"2","4->49","51->74","76->99"};
    // EXPECT_EQ(s.findMissingRanges(v, lower, upper), result); 
    EXPECT_EQ(s.findMissingRanges02(v, lower, upper), result); 
}

TEST(SolutionsingleNumber, test12)
{
    SolutionsingleNumber s{};
    std::vector<int> v{2, 2, 1};
    EXPECT_EQ(s.singleNumber(v), 1);
}

// TEST(SolutionisHappy, test12)
// {
//     SolutionisHappy s{};
//     EXPECT_EQ(s.isHappy03(19), true);
// }

// TEST(isIsomorphic, test01)
// {
//     std::string s1{"egg"};
//     std::string s2{"add"};
//     std::string s3{"foo"};
//     std::string s4{"bar"};
//     SolutionisIsomorphic s{};
//     auto result1 = s.isIsomorphic(s1, s2);
//     auto result2 = s.isIsomorphic(s3, s4);
//     EXPECT_EQ(result1, true);
//     EXPECT_EQ(result2, false);
// }

TEST(isIsomorphic, test02)
{
    std::string s1{"egg"};
    std::string s2{"add"};
    std::string s3{"foo"};
    std::string s4{"bar"};    
    std::string s5{"badc"};
    std::string s6{"baba"};
    SolutionisIsomorphic s{};
    auto result1 = s.isIsomorphic02(s1, s2);
    auto result2 = s.isIsomorphic02(s3, s4);
    auto result3 = s.isIsomorphic02(s5, s6);
    EXPECT_EQ(result1, true);
    EXPECT_EQ(result2, false);
    EXPECT_EQ(result3, false);
}

TEST(SolutionaddDigits, test12)
{
    SolutionaddDigits s{};
    EXPECT_EQ(s.addDigits(38), 2); 
}

// TEST(SolutionfindRestaurant, test1)
// {
//     SolutionfindRestaurant s{};
//     std::vector<std::string> v1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
//     std::vector<std::string> v2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
//     std::vector<std::string> result{"Shogun"};
//     EXPECT_EQ(s.findRestaurant(v1, v2), result); 
// }

// TEST(SolutionfindRestaurant, test11)
// {
//     SolutionfindRestaurant s{};
//     std::vector<std::string> v1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
//     std::vector<std::string> v2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
//     std::vector<std::string> result{"Shogun"};
//     EXPECT_EQ(s.findRestaurant02(v1, v2), result); 
// }

// TEST(SolutionfindRestaurant, test2)
// {
//     SolutionfindRestaurant s{};
//     std::vector<std::string> v1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
//     std::vector<std::string> v2{"KFC", "Shogun", "Burger King"};
//     std::vector<std::string> result{"Shogun"};
//     EXPECT_EQ(s.findRestaurant(v1, v2), result); 
// }

TEST(SolutionfindRestaurant, test22)
{
    SolutionfindRestaurant s{};
    std::vector<std::string> v1{"Shogun","Tapioca Express","Burger King","KFC"};
    std::vector<std::string> v2{"KFC","Shogun","Burger King"};
    std::vector<std::string> result{"Shogun"};
    EXPECT_EQ(s.findRestaurant02(v1, v2), result); 
}


// ["cbe","dcb","bbd","ddb","KFC"]
// ["cbc","bad","bcb","bbd","eda","edc","ddb","KFC"]
TEST(SolutionfindRestaurant, test23)
{
    SolutionfindRestaurant s{};
    std::vector<std::string> v1{"cbe","dcb","bbd","ddb","KFC"};
    std::vector<std::string> v2{"cbc","bad","bcb","bbd","eda","edc","ddb","KFC"};
    std::vector<std::string> result{"bbd"};
    EXPECT_EQ(s.findRestaurant02(v1, v2), result); 
}

// ["aac","bab","cca","KFC"]
// ["ade","dea","cca","KFC"]
TEST(SolutionfindRestaurant, test24)
{
    SolutionfindRestaurant s{};
    std::vector<std::string> v1{"aac","bab","cca","KFC"};
    std::vector<std::string> v2{"ade","dea","cca","KFC"};
    std::vector<std::string> result{"cca"};
    EXPECT_EQ(s.findRestaurant02(v1, v2), result); 
}

// using testing::UnorderedElementsAre;

TEST(SolutionintersectII, test1)
{
    SolutionintersectII s{};
    std::vector<int> v1{1, 2, 2, 1};
    std::vector<int> v3{4, 9, 5};
    std::vector<int> v4{9, 4, 9, 8, 4};
    std::vector<int> v2{2, 2 };
    std::vector<int> result{2, 2};
    std::vector<int> result2{9, 4};
    std::vector<int> result3{4, 9};
    EXPECT_EQ(s.intersect02(v1, v2), result); 
    EXPECT_EQ(s.intersect02(v3, v4), result2);    
    EXPECT_EQ(s.intersect03(v1, v2), result); 
    EXPECT_EQ(s.intersect03(v3, v4), result3); 
}

TEST(SolutioncontainsNearbyDuplicate, test1)
{
    SolutioncontainsNearbyDuplicate s{};
    std::vector<int> v1{1,2,3,1};
    std::vector<int> v2{1,0,1,1};
    std::vector<int> v3{1,2,3,1,2,3};
    EXPECT_EQ(s.containsNearbyDuplicate02(v1, 3), true); 
    EXPECT_EQ(s.containsNearbyDuplicate02(v2, 1), true); 
    EXPECT_EQ(s.containsNearbyDuplicate02(v3, 2), false); 
}

TEST(Logger, test1)
{
    Logger s{};
    EXPECT_EQ(s.shouldPrintMessage(1, "foo"), true);
    EXPECT_EQ(s.shouldPrintMessage(2, "bar"), true);
    EXPECT_EQ(s.shouldPrintMessage(3, "foo"), false);
    EXPECT_EQ(s.shouldPrintMessage(8, "bar"), false);
    EXPECT_EQ(s.shouldPrintMessage(10, "foo"), false);
    EXPECT_EQ(s.shouldPrintMessage(11, "foo"), true);
}

TEST(SolutiongroupAnagrams, test12)
{
    SolutiongroupAnagrams s{};
    // vector<vector<string>> SolutiongroupAnagrams::groupAnagrams02(vector<string>& strs) {
    vector<vector<string>> v_result{{"bat"}, {"eat", "tea", "ate"}, {"tan", "nat"}};
    vector<string> v_input{"eat", "tea", "tan", "ate", "nat", "bat"}; 
    
    vector<vector<string>> v_result1{{""}};
    vector<string> v_input1{""};

    EXPECT_EQ(s.groupAnagrams03(v_input), v_result);
    EXPECT_EQ(s.groupAnagrams03(v_input1), v_result1);
}

TEST(SolutionsortColors, test1)
{
    SolutionsortColors s{};
    vector<int> v_input1{2,0,2,1,1,0};
    vector<int> v_input2{2,0,1};
    vector<int> v_result1{0,0,1,1,2,2};
    vector<int> v_result2{0,1,2};
    s.sortColors02(v_input1);
    s.sortColors02(v_input2);
    EXPECT_EQ(v_input1, v_result1);
    EXPECT_EQ(v_input2, v_result2);
}

// vector out of scope
// TEST(SolutionheightCheckerII, test1)
// {
//     SolutionheightCheckerII s{};
//     std::vector<int> v{1,1,4,2,1,3};
//     std::vector<int> v2{5,1,2,3,4};
//     EXPECT_EQ(s.heightChecker(v), 3);
//     EXPECT_EQ(s.heightChecker(v2), 5);
// }

TEST(Solutioninsertionsort, test1)
{
    Solutioninsertionsort s{};
    std::vector<int> v{1,1,4,2,1,3};
    std::vector<int> v2{5,1,2,3,4};
    s.insertion_sort(v);
    s.insertion_sort(v2);
    std::vector<int> v_result{1,1,1,2,3,4};
    std::vector<int> v2_result{1,2,3,4,5};
    EXPECT_EQ(v, v_result);
    EXPECT_EQ(v2, v2_result);
}

TEST(SolutionpivotIndex, test1)
{
    SolutionpivotIndex s{};
    std::vector<int> v_input{1,7,3,6,5,6};
    EXPECT_EQ(s.pivotIndex(v_input), 3);
    EXPECT_EQ(s.pivotIndex02(v_input), 3);
}

TEST(SolutiondominantIndex, test1)
{
    SolutiondominantIndex s{};
    std::vector<int> v_input{1,2,3,4};
    std::vector<int> v_input2{3,6,1,0};
    EXPECT_EQ(s.dominantIndex(v_input), -1);
    EXPECT_EQ(s.dominantIndex(v_input2), 1);
}

TEST(SolutionplusOne, test1)
{
    SolutionplusOne s{};
    std::vector<int> v_input{1,2,3};
    std::vector<int> v_result{1,2,4};
    //[8,9,9,9]    
    std::vector<int> v_input02{8,9,9,9};
    std::vector<int> v_result02{9,0,0,0};
    EXPECT_EQ(s.plusOne(v_input), v_result);
    EXPECT_EQ(s.plusOne(v_input02), v_result02);
}

TEST(SolutionaddBinary, test1)
{
    SolutionaddBinary s{};
    std::string s1{"11"};
    std::string s2{"1"};
    std::string result{"100"};    

    std::string s11{"1010"};
    std::string s21{"1011"};
    std::string result2{"10101"};

    EXPECT_EQ(s.addBinary(s1, s2), result);
    EXPECT_EQ(s.addBinary02(s1, s2), result);

    EXPECT_EQ(s.addBinary(s11, s21), result2);
    EXPECT_EQ(s.addBinary02(s11, s21), result2);
}

TEST(SolutionlongestCommonPrefix, test1)
{
    SolutionlongestCommonPrefix s{};
    std::vector<std::string> input{"flower","flow","flight"};
    std::vector<std::string> input1{"aa", "ab"};
    std::string s1{"fl"};
    std::string s2{"a"};
    EXPECT_EQ(s.longestCommonPrefix(input), s1);
    EXPECT_EQ(s.longestCommonPrefix(input1), s2);
}

TEST(SolutionarrayPairSum, test1)
{
    SolutionarrayPairSum s{};
    std::vector<int> input{1, 4, 3, 2};
    EXPECT_EQ(s.arrayPairSum(input), 4);
}

TEST(quickSort, test1)
{
    std::vector<int> input{1, 4, 3, 2};
    std::vector<int> result{1, 2, 3, 4};
    quickSort(input, 0, input.size() - 1);
    EXPECT_EQ(input, result);

    // std::vector<int> input2{1, 4, 3, 2};
    // std::vector<int> result2{1, 2, 3, 4};
    // myquicksort(input2, 0, input2.size() - 1);
    // EXPECT_EQ(input2, result2);
}

TEST(SolutionthreeSum, DISABLED_Test1)
{
    SolutionthreeSum s{};
    std::vector<int> input1{-1,0,1,2,-1,-4};
    std::vector<int> input2{-1,0,1,2,-1,-4,-2,-3,3,0,4};
    std::vector<vector<int>> result1{{-1,-1,2}, {-1,0,1}};
    std::vector<vector<int>> result2{{-4,0,4},{-4,1,3},{-3,-1,4},{-3,0,3},{-3,1,2},{-2,-1,3},{-2,0,2},{-1,-1,2},{-1,0,1}};
    EXPECT_EQ(s.threeSum03(input1), result1);
    EXPECT_EQ(s.threeSum03(input2), result2);
}


TEST(minSubArrayLen, test1)
{
    SolutionminSubArrayLen s{};
    std::vector<int> input1{2,3,1,2,4,3};
    std::vector<int> input2{1,4,4};
    std::vector<int> input3{1,1,1,1,1,1,1,1};
    EXPECT_EQ(s.minSubArrayLen(7, input1), 2);
    EXPECT_EQ(s.minSubArrayLen(4, input2), 1);
    EXPECT_EQ(s.minSubArrayLen(11, input3), 0);
}

TEST(SolutionminCostClimbingStairs, test1)
{
    SolutionminCostClimbingStairs s{};
    std::vector<int> input1{10,15,20};
    std::vector<int> input2{1,100,1,1,1,100,1,1,100,1};
    EXPECT_EQ(s.minCostClimbingStairs01(input1), 15);
    EXPECT_EQ(s.minCostClimbingStairs(input1), 15);
    EXPECT_EQ(s.minCostClimbingStairs01(input2), 6);
    EXPECT_EQ(s.minCostClimbingStairs(input2), 6);
    EXPECT_EQ(s.minCostClimbingStairs03(input1), 15);
    EXPECT_EQ(s.minCostClimbingStairs03(input2), 6);
    EXPECT_EQ(s.minCostClimbingStairs02(input1), 15);
    EXPECT_EQ(s.minCostClimbingStairs02(input2), 6);
}