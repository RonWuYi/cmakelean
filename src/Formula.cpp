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

void SolutionduplicateZeros::duplicateZeros(vector<int>& arr) {
    int n = arr.size(), j = n + count(arr.begin(), arr.end(), 0);
    for (int i = n - 1; i >= 0; --i) {
        if (--j < n)
        {
            arr[j] = arr[i];
        }
        if (arr[i] == 0 && --j < n)
        {
            arr[j] = 0;
        }
    }
}

int SolutionmySqrt::mySqrt(int x) {
    long long s=0, e=x, ans, mid;
    while (s<=e) {
        mid=(s+e)/2;
        if (mid*mid==x) return mid;
        else if (mid*mid<x) {
            s=mid+1;
            ans=mid;
        }
        else {
            e=mid-1;
        }
    }
    return ans;
}

std::vector<int> SolutionsearchRange::searchRange(std::vector<int>& nums, int target)
{
    int lower_bound = findBound(nums, target, true);

    if (lower_bound == -1)
    {
        std::vector<int> v{-1, -1};
        return v;
    }

    int upper_bound = findBound(nums, target, false);

    std::vector<int> v{lower_bound, upper_bound};
    return v;

}

int SolutionsearchRange::findBound(std::vector<int>& nums, int target, bool isFirst)
{
    int N = nums.size();
    int begin = 0;
    int end = N - 1;
    while (begin <= end)
    {
        int mid = (begin + end) / 2;

        if (nums[mid] == target)
        {
            if (isFirst)
            {
                if (mid == begin || nums[mid-1] < target)
                {
                    return mid;
                }
                end = mid -1;
            }
            else
            {
                if (mid == end || nums[mid +1] > target)
                {
                    return mid;
                }
                begin = mid + 1;
            }
        }
        else if (nums[mid] > target)
            end = mid -1;
        else
            begin = mid + 1;
    }
    return -1;
}

bool SolutionareNumbersAscending::areNumbersAscending(string s)
{
    int prev = 0, cur = 0;
    for (auto ch: s)
    {
        if (isdigit(ch))
            cur = cur * 10 + (ch - '0');
        else if (cur != 0)
        {
            if (prev >= cur)
                return false;
            prev = cur;
            cur = 0;
        }
    }
    return cur == 0 || prev < cur;
}

double SolutionmyPow::myPow(double x, int n)
{
    {
        long long N = n;
        if (N < 0)
        {
            x = 1/x;
            N = -N;
        }
        double ans = -1;
        for (long long i = 0; i < N; i++)
        {
            ans = ans * x;
        }
        return ans;
    }
}

double SolutionmyPow::myPow02(double x, int n)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }
    double ans = 1;
    double currecnt_product = x;

    for (long long i = N; i ; i /= 2)
    {
        if ((i%2) == 1)
        {
            ans = ans * currecnt_product;
        }
        currecnt_product = currecnt_product * currecnt_product;
    }
    return ans;
}

int SolutionlengthOfLongestSubstring::lengthOfLongestSubstring(string s) {
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (checkRepetition(s, i, j))
            {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}

bool SolutionlengthOfLongestSubstring::checkRepetition(string& s, int start, int end) {
    vector<int> chars(128);
    for (int i = start; i <= end; i++)
    {
        char c = s[i];
        chars[c]++;
        if (chars[c] > 1)
        {
            return false;
        }
    }
    return true;
}

    // int dx[4]{0, 0, -1, 1};
    // int dy[4]{1, -1, 0, 0};
bool SolutionisRobotBounded::isRobtBounded(string instructions) {
    int x, y, direct;
    x = y = direct = 0;
    instructions += instructions + instructions + instructions;

    for (auto c: instructions) {
        if (c == 'L')
            direct = turnLeft(direct);
        else if ( c == 'R')
            direct = turnRight(direct);
        else {
            x += dx[direct];
            y += dy[direct];
        }
    }

    if (x == 0 && y == 0)
        return true;
    return false;
}

int SolutionisRobotBounded::turnLeft(int d) {
    if (d == 0) return 2;
    if (d == 2) return 1;
    if (d == 1) return 3;
    return 0; 
}

int SolutionisRobotBounded::turnRight(int d) {
    if (d == 0) return 3;
    if (d == 3) return 1;
    if (d == 1) return 2;
    return 0; 
}
