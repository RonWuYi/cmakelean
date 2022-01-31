#ifndef EXAMPLEPROJECT_FORMULA_H
#define EXAMPLEPROJECT_FORMULA_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
        // if (count == 0)
        //     return true;
        // else
        //     return false;
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

// class MiniStack {
// public:
//     MiniStack(int val) {
//         data.resize(val);
//     };

//     void push(int val) {
//         data.push_back(val);
//     }

//     void pop() {
//         if (isEmpty())
//             return;
//         // data.pop_back(); 
//         // data = data[1:];
//     }

//     int top() { return data.front(); };

//     int getMin() { 
//         int sum = data[0];
//         // return data[1]; 
//         for (auto i : v)
//         {
//             if (v < sum)
//                 sum = v;
//             /* code */
//         }
//         return sum;
        
//     }

//     bool isEmpty() const { return data.isEmpty(); }

// private:
//     vector<int> data;
//     stack<int> s1;
//     stack<int> s2;


class Solutionislands {
public:
    static void dfs(vector<vector<char>>& grid, int r, int c);
    // {
    //     int nr = grid.size();
    //     int nc = grid[0].size();

    //     grid[r][c] = '0';
    //     if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
    //     if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
    //     if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
    //     if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
    // }

    static int numIslands(vector<vector<char>>& grid); 
    // {
    //     int nr = grid.size();
    //     if (!nr) return 0;
    //     int nc = grid[0].size();

    //     int num_islands = 0;
    //     for (int r = 0; r < nr; ++r) {
    //         for (int c = 0; c < nc; ++c) {
    //             if (grid[r][c] == '1') {
    //                 ++num_islands;
    //                 dfs(grid, r, c);
    //             }
    //         }
    //     }
    //     // int i = 0;
    //     return num_islands;
    // }
};
// };

#endif //EXAMPLEPROJECT_FORMULA_H