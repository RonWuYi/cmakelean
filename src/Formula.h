#ifndef EXAMPLEPROJECT_FORMULA_H
#define EXAMPLEPROJECT_FORMULA_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>

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
    static vector<int> inorderTraversal(TreeNode* root);
    static vector<int> postorderTraversal(TreeNode* root);
};

#endif //EXAMPLEPROJECT_FORMULA_H