#include "Formula.h"

int sum(vector<int> v) {
    int sum = 0;
    for (auto i : v) {
        sum += i;
    }
    return sum;
}

int min_element(vector<int> v) {
    int min = v[0];
    for (auto i : v) {
        if (i < min) {
            min = i;
        }
    }
    return min;
}

int Formula::bla(int arg1) {
    return arg1 * 2;
}

int EasySolution::maxSubArray(vector<int>& nums) {
    int sum = nums[0];
    int temp = nums[0];

    for (size_t i = 1; i < nums.size(); ++i)
    {
        temp = max(nums[i], temp + nums[i]);
        sum = max(sum, temp);
    }
    return sum;
}

vector<int> EasySolution::preorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    result.push_back(root->val);
    vector<int> left = preorderTraversal(root->left);
    vector<int> right = preorderTraversal(root->right);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

vector<int> EasySolution::preorderTraversaliterative(TreeNode* root)
{
    vector<int> answer;
    stack<TreeNode*> s;
    if (root)
    {
        s.push(root);
    }
    TreeNode* cur;
    while (!s.empty()){
        cur = s.top();
        s.pop();
        answer.push_back(cur->val);
        if (cur->right)
        {
            s.push(cur->right);
        }
        if (cur->left)
        {
            s.push(cur->left);
        }
    }
    return answer;
}

vector<int> EasySolution::inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root = nullptr)
    {
        return result;
    }

    vector<int> left = inorderTraversal(root->left);
    vector<int> right = inorderTraversal(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->val);
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

vector<int> EasySolution::postorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
        return result;
    }
    vector<int> left = postorderTraversal(root->left);
    vector<int> right = postorderTraversal(root->right);
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    result.push_back(root->val);
    return result;
}

bool MyQueue01::enQueue(int x) {
    data.push_back(x);
    return true;
}

bool MyQueue01::deQueue(){ 
    if (isEmpty()) return false;
    p_start++;
    return true;}

MovingAverageVector::MovingAverageVector(int size) {
    data.resize(size);
    capacity = size;
    sum = 0;
}

double MovingAverageVector::next(int val) {
    for (auto p: data)
    {
        sum += p;
    }
    
    return sum/capacity;
}

void Solutionislands::dfs(vector<vector<char>>& grid, int r, int c)
{
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
}

int Solutionislands::numIslands(vector<vector<char>>& grid)
{
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
                ++num_islands;
                dfs(grid, r, c);
            }
        }
    }
    // int i = 0;
    return num_islands;
}

ListNode*  SolutionreverseList::reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* n;

    while(cur!=nullptr) {
        n=cur->next;
        cur->next=prev;
        prev=cur;
        cur=n;
    }
    return prev;
}

