#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
#include <random>
#include <memory>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstdint>
#include <climits>
#include <limits>
#include <limits.h>
#include <list>
#include <map>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Formula {
public:
    static int bla(int arg1);
};

class EasySolution {
public:
    static int maxSubArray(vector<int>& nums);
    static vector<int> preorderTraversal(TreeNode* root);
    static vector<int> preorderTraversaliterative(TreeNode* root);
    static vector<int> inorderTraversal(TreeNode* root);
    static vector<int> postorderTraversal(TreeNode* root);
};


class MyQueue01 {
private:
    vector<int> data;
    int p_start;

public:
    MyQueue01() : p_start(0) {}
    bool enQueue(int x);
    bool deQueue();

    int Front() { return data[p_start]; }
    bool isEmpty() { return p_start >= data.size(); }
};

struct Node {
    int value;
    Node* pNext;
    Node(int i) {
        value = i;
        pNext = nullptr;
    }
};

class MyCircularQueue01 {
public:
    MyCircularQueue01(int k) {
        capacity = k;
        count = 0;
        pHead = pTail = nullptr;
    }
    
    bool enQueue(int value) {
        if (count == capacity) {
            return false;
        }
        Node* newNode = new Node(value);
        if (count == 0)
        {
            pHead = newNode;
            pTail = pHead;
        }
        else {
            pTail->pNext = newNode;
            pTail = newNode;
        }
        count += 1;
        return true;
    }
    
    bool deQueue() {
        if (count == 0)
        {
            /* code */
            return false;
        }
        pHead = pHead->pNext;
        count -= 1;
        return true;
    }
    
    int Front() {
        if (count == 0)
        {
            return -1;
        }

        return pHead->value;
    }
    
    int Rear() {
        if (count == 0)
        {
            return -1;
        }

        return pTail->value;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return capacity == count;
    }

private:
    int capacity;
    int count;
    Node* pHead;
    Node* pTail;
};

class MyCircularQueueVector
{
private:
    vector<int> data;
    int head;
    int tail;
    int size;

public:
    MyCircularQueueVector(int k) {
        data.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }

        if (isEmpty())
        {
            head = 0;
        }
        
        tail = (tail + 1) % size;
        data[tail] = value;
        return true;
    }

    bool deQueue() { 
        if (isEmpty())
        {
            return false;
        }
        if (head==tail) {
            head = -1;
            tail = -1;
            return true;
        }
        head = (head + 1) % size;
        return true;
    }

    int Front() {
        if (isEmpty())
        {
            return -1;
        }
        return data[head];
    }

    int Rear() {
        if (isEmpty())
        {
            return -1;
        }
        return data[tail];
    }

    bool isEmpty() {
        return head == -1;
    }

    bool isFull() {
        return ((tail + 1) %size == head);
    }
};

class MovingAverageVector {
public:
    MovingAverageVector(int size);
    double next(int val);
private:
    vector<int> data;
    int capacity;
    int sum;
};

class MovingAverage01 {
public:
    MovingAverage01(int val)
    {
        // value = val;
        Node* node = new Node(0);
        pHead = node;
        pNext = nullptr;

        value = 0;
        pTail = 0;
        capacity = val;
    }

    double next(int val)
    {
        Node* node = new Node(val);
        pNext = node;
        return 1.0;
    }

private:
    int value;
    int capacity;
    Node* pHead;
    int pTail;
    Node* pNext;
};

class MyStackLIFO {
private:
    vector<int> data;
public:
    void push(int x) { data.push_back(x); }

    bool isEmpty() const { return data.empty(); }
    bool pop() { 
        if (isEmpty())
            return false;

        data.pop_back();
        return true;}
};

class Solutionislands {
public:
    static void dfs(vector<vector<char>>& grid, int r, int c);
    static int numIslands(vector<vector<char>>& grid); 
};

class SolutionreverseList {
public:
    static ListNode* reverseList(ListNode* head);
};

class SolutionsearchBST {
public:
    static TreeNode* searchBST(TreeNode* root, int val);
};

class SolutionduplicateZeros {
public:
    static void duplicateZeros(vector<int>& arr);
};

class SolutionmySqrt {
public:
    static int mySqrt(int x);
};

class SolutionsearchRange {
public:
    static std::vector<int> searchRange(std::vector<int>& nums, int target);
private:
    static int findBound(std::vector<int>& nums, int target, bool isFirst);
};

class SolutionareNumbersAscending{
public:
    bool areNumbersAscending(string s);
};

class SolutionmyPow
{
public:
    double myPow(double x, int n);
    double myPow02(double x, int n);
};

class SolutionlengthOfLongestSubstring
{
public:
    int lengthOfLongestSubstring(string s); 
    bool checkRepetition(string& s, int start, int end);
};

class SolutionisRobotBounded
{
public:
    int dx[4]{0, 0, -1, 1};
    int dy[4]{1, -1, 0, 0};

    int turnLeft(int d);
    int turnRight(int d);

    bool isRobtBounded(string instructions);
};

class SolutionfindDuplicate
{
public:
    int findDuplicate(vector<int>& nums);
    int findDuplicate02(vector<int>& nums);
    int findDuplicate03(vector<int>& nums);

    int store(vector<int>& nums, int cur);
};

class SolutionlongestPalindrome
{
public:
    string longestPalindrome(string s);
    int longestPalindrome01(string s);
    string get_max_len(string s, int left, int right);

    int longestPalindrome02(string s);
};

class SolutionrunningSum
{
public:
    vector<int> runningSum01(vector<int>& nums);
};

class SolutionclimbStairs
{
public:
    unordered_map<int, int> cache;
    int climbStairs(int n);
    int climbStairs02(int n);
    int climbStairs03(int n);
};

class SolutionminCostClimbingStairs
{
public:
    int minCostClimbingStairs(vector<int>& cost);
};

class SolutionmaxArea02 {
public:
    int maxArea(vector<int>& height);
};

class SolutionisBalanced {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        return abs(height(root->left) - height(root->right)) < 2 &&
            isBalanced(root->right) && isBalanced(root->left);
    }

private:
    int height(TreeNode *root) {
        if (root == nullptr) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
};

class SolutionmaxProfit {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profix = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_price)
                min_price = prices[i];
            else if ((prices[i] - min_price) > max_profix)
                max_profix = prices[i] - min_price;
        }
        return max_profix;
    }
};

class SolutionnumIslands {
public:
    void dfs(vector<vector<char>>& grid, int r, int c);
    int numIslands(vector<vector<char>>& grid); 
};

class SolutiondailyTemperatures {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures);
};

class SolutiondecodeString : public SolutiondailyTemperatures{
public:
    string decodeString(string s);
    string decodeString02(string s);
};

class SolutionisInterleave {
public:
    bool isInterleave(string s1, string s2, string s3);
};

class SolutionfloodFill {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int val, int newColor);
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color);
    vector<vector<int>> floodFill02(vector<vector<int>>& image, int sr, int sc, int color);
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class SolutionisValidBST {
public:
    bool isValidBST(TreeNode* root); 
    // {
    //     if (!root) return;
    //     else if (root->left == nullptr and root->right == nullptr) return true;
    //     else if (root->left == nullptr and root->right != nullptr) 
    //         return (root-> val > root->left->val) && (isValidBST(root->left));        
    //     else if (root->left != nullptr and root->right == nullptr) 
    //         return (root-> val < root->right->val) && (isValidBST(root->right));
    //     else return (root->val > root->left->val 
    //                 && root->val < root->right->val
    //                 && isValidBST(root->right)
    //                 && isValidBST(root->left));
    // }
    bool isValidBST02(TreeNode* root);
    bool isValidBSTStack(TreeNode* root);

private:
    bool validate(TreeNode* root, TreeNode* low, TreeNode* high);
    void update(TreeNode* root, TreeNode* low, TreeNode* high);
    std::stack<TreeNode*> stk, lower_limits, upper_limits;
};

class SolutionisPalindrome {
public:
    bool isPalindrome(string s);
    bool isPalindrome02(string s);
};

class SolutiontwoSum {
public:
    vector<int> twoSum01(vector<int>& nums, int target);
    vector<int> twoSum02(vector<int>& nums, int target);
};

enum State { q0, q1, q2, qd};

class StateMachine {
public:
    StateMachine();
    void transition(char& ch);
    State currentState;
    int result;
    int sign;

    void toStateQ1(char& ch);
    void toStateQ2(int digit);
    void toStateQd();
    void appendDigit(int& digit);
    int getInteger();
    State getState();
};

class SolutionmyAtoi {
public:
    int myAtoi(string s);
    int myAtoi01(string s);
    int myAtoi02(string s);
};

class SolutionreverseString {
public:
    void reverseString(vector<char>& s);
    void reverseString02(vector<char>& s);
};

class SolutionfindMissingRanges {
public:
    string get_range(int start, int end);
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper);
    vector<string> findMissingRanges02(vector<int>& nums, int lower, int upper);
};


class MyHashMap {
private:
    std::vector<std::pair<int, int>> p;
public:
    MyHashMap();
    void put(int key, int value);
    int get(int key);
    void remove(int key);
};

class MyHashMap02 {
private:
    std::vector<std::list<std::pair<int, int>>> m_data;
    size_t m_size = 10000;

public:
    MyHashMap02();
    void put(int key, int value);
    int get(int key);
    void remove(int key);
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums);
};


class SolutionsingleNumber {
public:
    int singleNumber(vector<int>& nums);
};


class Solutionintersection {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
    vector<int> intersection02(vector<int>& nums1, vector<int>& nums2);
};

class SolutionisHappy {
public:
    bool isHappy(int n);
    int isHappy02(int n);
    bool isHappy03(int n);
private:
    int digitSquareSum(int n);
};

class SolutionisIsomorphic {
public:
    bool isIsomorphic(string s, string t);
    bool isIsomorphic02(string s, string t);
private:
    std::unordered_map<char, int> get_map(string t);
};

class SolutionaddDigits {
public:
    int addDigits(int num);
};

class SolutionfindRestaurant {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2);
    vector<string> findRestaurant02(vector<string>& list1, vector<string>& list2);
};

class SolutionfirstUniqChar {
public:
    int firstUniqChar(string s);
};

class SolutionintersectII {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
    vector<int> intersect02(vector<int>& nums1, vector<int>& nums2);
    vector<int> intersect03(vector<int>& nums1, vector<int>& nums2);
};


class SolutioncontainsNearbyDuplicate {
public:
    // bool containsNearbyDuplicate(vector<int>& nums, int k);
    bool containsNearbyDuplicate02(vector<int>& nums, int k);
};

class LoggershouldPrintMessage {
public:
    LoggershouldPrintMessage();
    bool shouldPrintMessage(int timestamp, string message);
};


class Logger {
public:
    Logger();
    
    bool shouldPrintMessage(int timestamp, string message);

private:
    std::unordered_map<std::string, int> temp;
};

class SolutiongroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs);
    vector<vector<string>> groupAnagrams02(vector<string>& strs);
    vector<vector<string>> groupAnagrams03(vector<string>& strs);
};


class SolutionsortColors {
public:
    void sortColors(vector<int>& nums);
    void sortColors02(vector<int>& nums);
};


class SolutionheightChecker {
public:
    SolutionheightChecker();
    int heightChecker(vector<int>& heights);

private:
    void bubble_sort(vector<int>& heights);
    vector<int> heights_copy;
};


class SolutionheightCheckerII {
public:
    int heightChecker(vector<int>& heights);
};

class Solutioninsertionsort {
public:
    void insertion_sort(vector<int>& heights);
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class SolutionlevelOrderBottom {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root);
// };



class SolutioninsertionSortList {
public:
    ListNode* insertionSortList(ListNode* head);
    ListNode* insertionSortListII(ListNode* head);
};


class SolutionpivotIndex {
public:
    int pivotIndex(vector<int>& nums);
    int pivotIndex02(vector<int>& nums);
};


class SolutiondominantIndex {
public:
    int dominantIndex(vector<int>& nums);
};


class SolutionplusOne {
public:
    vector<int> plusOne(vector<int>& digits);
};


class SolutionfindDiagonalOrder {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat);
};


class SolutionaddBinary {
public:
    string addBinary(string a, string b);
};

class SolutionthreeSum {
public:
    vector<vector<int>> threeSum(vector<int>& nums);
};

class SolutionstrStr {
public:
    int strStr(string haystack, string needle); 
};


class SolutionlongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string>& strs);
    void reverse(int *v, int N);
};


class SolutionarrayPairSum {
public:
    int arrayPairSum(vector<int>& nums);
};