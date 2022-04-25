#ifndef EXAMPLEPROJECT_FORMULA_H
#define EXAMPLEPROJECT_FORMULA_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
#include <random>
#include <memory>
#include <ranges>

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

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
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
            // pHead->value = value;
            pTail = pHead;
        }
        else {
            // pTail->value = value;
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

#endif //EXAMPLEPROJECT_FORMULA_H