#include "Formula.h"
#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <array>


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
    if (root == nullptr)
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
    
    // return sum / static_cast<int>(capacity);
    return sum / capacity;
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

int SolutionfindDuplicate::findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == nums[i+1]) {
            return nums[i];
        }
    }
    return -1;
}

int SolutionfindDuplicate::findDuplicate02(vector<int>& nums) {
    std::unordered_set<int> seen;
    for (auto& num: nums) {
        if (seen.count(num))
            return num;
        seen.insert(num);
    }
    return -1;
}

int SolutionfindDuplicate::findDuplicate03(vector<int>& nums) {
    return store(nums, 0);
    
}

int SolutionfindDuplicate::store(vector<int>& nums, int cur) {
    if (cur == nums[cur])
        return cur;
    int nxt = nums[cur];
    nums[cur] = cur;
    return store(nums, nxt);
}

string SolutionlongestPalindrome::get_max_len(string s, int left, int right) {
    
    while (left >= 0 and right <= s.length() and s[left] == s[right]) {
        left -= 1;
        right += 1;
    }
    std:string temp = s.substr(left, right-left);
    return temp;
}

string SolutionlongestPalindrome::longestPalindrome(string s) {
    
    std::string res{};
    for (auto i = 0; i < s.length(); i++)
    {
        auto temp = get_max_len(s, i, i);
        if (temp.length() > res.length())
            res = temp;
        auto tmp = get_max_len(s, i, i+1);
        if (tmp.length() > res.length())
            res = tmp;
    }
    return res;
}

int SolutionlongestPalindrome::longestPalindrome01(string s) {
    
    std::string res{};
    for (auto i = 0; i < s.length(); i++)
    {
        std::string temp = get_max_len(s, i, i);
        if (temp.length() > res.length())
            res = temp;
        std::string tmp = get_max_len(s, i, i+1);
        if (tmp.length() > res.length())
            res = tmp;
    }
    return res.length();
}

int SolutionlongestPalindrome::longestPalindrome02(string s) {
    int odds = 0;
    for (char c='A'; c<='z'; c++)
    {
        odds += std::count(s.begin(), s.end(), c) & 1;
    }
    return s.size() - odds + (odds > 0);
}

vector<int> SolutionrunningSum::runningSum01(vector<int>& nums) {
    vector<int> result {};
    for (auto i = 0; i < nums.size(); i++)
    {
        if (i==0)
        {
            result.push_back(nums[i]);
        }
        else {
        result.push_back(result[i-1] + nums[i]);
        }
    }
    return result;
}

// vector<int> SolutionrunningSum::runningSum02(vector<int>& nums) {
//     vector<int> result {};
//     for (auto i = 0; i < nums.size(); i++)
//     {
//         if (i==0)
//         {
//             result[0] = nums[i];
//         }
//         else {
//             result[i] = result[i-1] + nums[i];
//         }
//     }
//     return result;
// }

int SolutionclimbStairs::climbStairs(int n) {
    vector<int> steps(n,0);
    steps[0] = 1;
    steps[1] = 2;

    for(int i=2; i<n; i++)
    {
        steps[i] = steps[i-1] + steps[i-2];
    }

    return steps[n-1];
}

int SolutionclimbStairs::climbStairs02(int n) {
    
    long long a = 1, b = 1;
    while (n--) {
        a = (b += a) -a;
    }
    return a;
}


int SolutionclimbStairs::climbStairs03(int n) {
    if (cache.find(n) != cache.end())
        return cache[n];
    int result = 0;
    if (n ==  0) result = 0;
    else if (n == 1) result = 1;
    else if (n == 2) result = 2;
    else {
        result = climbStairs03(n-1) + climbStairs03(n-2);
    }
    cache[n] = result;
    return result;
}

/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/
int SolutionminCostClimbingStairs::minCostClimbingStairs(vector<int>& cost) {
    std::unordered_map<int, int> cache;
    if (cache.find(cost.size()) != cache.end())
        return cache[cost.size()];

    int result = 0;
    if (cost.size() == 0) result = 0;
    else if (cost.size() == 1) result = cost[1];
    else if (cost.size() == 2) result = min(cost[1],cost[2]);
    else {
        result = cost[0] + min(cost[1], cost[2]);
        for (int i = 3; i < cost.size(); i++)
        {
            result = cost[i] + min(result, cache[i-1] + cache[i-2]);
        }
    }
    cache[cost.size()] = result;
    return result;
    
}

int SolutionmaxArea02::maxArea(vector<int>& height) {
    int max = 0;    
    int i = 0;
    int j = height.size()-1;
    while (i < j)
    {
        int area = (j-i) * min(height[i], height[j]);
        if (area > max)
            max = area;
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return max;
}

void SolutionnumIslands::dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1') dfs(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1') dfs(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') dfs(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1') dfs(grid, r, c + 1);
}

int SolutionnumIslands::numIslands(vector<vector<char>>& grid) {
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
    return num_islands;
}

// [73,74,75,71,69,72,76,73]
vector<int> SolutiondailyTemperatures::dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size());
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        int j = i + 1;
        while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
            if (res[j] > 0)
                j = res[j] + j;
            else 
                j = temperatures.size();
        }
        if (j < temperatures.size())
            res[i] = j - i;
    }
    return res; 
}

string SolutiondecodeString::decodeString(string s) {
    stack<char> mystack;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == ']') {
            string decodeString = "";
            while (mystack.top() != '[') {
                decodeString += mystack.top();
                mystack.pop();
            }
            mystack.pop();
            int base = 1; //
            int k = 0;
            // get the number k
            while (!mystack.empty() && ((mystack.top() >=47) && (mystack.top() <= 57)))
            {
                k = k + (mystack.top() - '0') * base;
                mystack.pop();
                base *= 10;
            }
            int currenLen = decodeString.size();
			// while (k != 0)
			while (k--)
			{
				for (int j = decodeString.size() - 1; j >= 0; j--) {
				// for (int j = decodeString.size(); j > 0; j--) {
					mystack.push(decodeString[j]);
				}
				// k--;
			}
        }
		else {
			mystack.push(s[i]);
		}
        // mystack.push(s[i]);
    }
	string result{};
	for (size_t i = mystack.size(); i > 0; i--) {
		result = mystack.top() + result;
		mystack.pop();
	}
	return result;
}

string SolutiondecodeString::decodeString02(string s) {
    stack<int> countStack; 
    stack<string> stringStack; 
    string currentString;
    int k = 0;

    for (auto ch: s)
    {
        if (isdigit(ch)) {
            k = k*10 + ch - '0';
        } else if (ch == '[') {
            countStack.push(k);
            stringStack.push(currentString);
            currentString = "";
            k = 0;
        } else if (ch == ']') {
            string decodeString = stringStack.top();
            stringStack.pop();

            for (int currentK = countStack.top(); currentK > 0; --currentK) {
                decodeString = decodeString + currentString;
            }
            countStack.pop();
            currentString = decodeString;
        } else {
            currentString = currentString + ch;
        }
    }
    return currentString;
}

// vector<vector<int>> SolutionfloodFill::floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//     std::vector<std::pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
//     std::unordered_set<std::pair<int, int>> visited = {{sr, sc}};
    
//     auto x = image[0].size();
//     auto y = image.size();

//     if (image[sr][sc] != color)
//         image[sr][sc] = color;
//     // while (true) {
//     for (auto& p : visited)
//     {
//         for (auto& q: directions)
//         {
//             auto temp = std::pair<int, int>(sr +q.first, sc +q.second);
//             if ( (sr + q.first) < x && (sc + q.second < y) && !visited.contains(temp))
//                 visited.insert(temp);
//         }
    
//     }
        
//     for (auto& p: visited)
//     {
//         if (image[p.first][p.second] != color)
//             image[p.first][p.second] = color;
//     }

//     return image;
// }

vector<vector<int>> SolutionfloodFill::floodFill02(vector<vector<int>>& image, int sr, int sc, int color) {
    int val = image[sr][sc];
    dfs(image,sr,sc,val,color);
    return image;
}

void SolutionfloodFill::dfs(vector<vector<int>>& image, int i, int j, int val, int newColor) {
    if (i <0 || i >= image.size() || j < 0 || j >= image[0].size() 
    || image[i][j] == newColor || image[i][j] != val) {
        return;
    }

    image[i][j] = newColor;
    dfs(image, i-1, j, val, newColor);
    dfs(image, i+1, j, val, newColor);
    dfs(image, i, j-1, val, newColor);
    dfs(image, i, j+1, val, newColor);
}

bool SolutionisValidBST::isValidBST02(TreeNode* root) {
    if (root == nullptr) return true;
    if (((root->left != nullptr) && (root->val <= root->left->val)) || 
    (root->right != nullptr && root->val >= root->right->val)) return false;

    // return isValidBST02(root, root->right);
    return true;
}

bool SolutionisValidBST::validate(TreeNode* root, TreeNode* low, TreeNode* high) {
    if (root == nullptr) return true;    
    if (((low != nullptr) && (root->val <= low->val)) ||
        ((high != nullptr) && (root->val >= high->val)))
        return false;
    return validate(root-> right, root, high) && validate(root-> left, low, root);
}

bool SolutionisValidBST::isValidBST(TreeNode* root) {
    return validate(root, nullptr, nullptr);
    
}

void SolutionisValidBST::update(TreeNode* root, TreeNode* low, TreeNode* high) {
    stk.push(root);
    lower_limits.push(low);
    upper_limits.push(high);
}

bool SolutionisValidBST::isValidBSTStack(TreeNode* root) {
    TreeNode* low = nullptr;
    TreeNode* high = nullptr;
    update(root, low, high);

    while (!stk.empty()) {
        root = stk.top();
        stk.pop();
        low = lower_limits.top();
        upper_limits.pop();
        high = upper_limits.top();
        upper_limits.pop();

        if (root == nullptr)
            continue;

        TreeNode* val_node = root;
        if (low != nullptr and val_node->val <= low->val) {
            return false;
        }

        if (high != nullptr and val_node->val >= high->val) {
            return false;
        }
        update(root->right, val_node, high);
        update(root->left, low, val_node);
    }
    return true;
}

vector<int> SolutiontwoSum::twoSum01(vector<int>& nums, int target) {
    std::vector<int> v{};
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (target == nums[i] + nums[j])
            {
                v.push_back(i);
                v.push_back(j);
                // std::vector<int> v{i, j};
                // return v;
                break;
            }
        }
    }
    return v;
}

vector<int> SolutiontwoSum::twoSum02(vector<int>& nums, int target) {
    auto temp = std::vector<std::pair<int, int>>();
    auto final_result = std::vector<int>();
    for (int i = 0; i < nums.size(); i++)
    {
        auto result = target - nums[i];
        auto result_pair = std::pair<int, int>(result, i);
        if (!temp.empty())
        {
            for (auto& p: temp)
            {
                if (p.first == result)
                {
                    final_result.push_back(p.second);
                    final_result.push_back(i);
                    break;
                }
            }
        }
        temp.push_back(std::pair<int, int>(nums[i], i));
    }
    
    return final_result;
}

bool SolutionisPalindrome::isPalindrome(string s) {
    if (s.empty() || s.length() == 1) {
        return true;
    }
    auto flag = true;
    std::string temp{};
    for (auto p: s)
    {
        if (p >= 'A' && p <= 'z')
        {
            if (p > 'Z')
                p = p - 32;
            temp += p;
        }
    }

    for (int i = 0; i < temp.length(); i++)
    {
        if (i > (temp.length() / 2) -1)
            break;
        auto temp1 = temp[i];
        auto len = temp.length();
        auto temp2 = temp[temp.length() - 1 - i];
        // if(temp[i] != temp[temp.length() - i])
        if(temp1 != temp2)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool SolutionisPalindrome::isPalindrome02(string s) {
    std::string filtered_str, reversed_str;

    for (auto ch :s)
    {
        if (isalnum(ch))
            filtered_str += tolower(ch);
    }

    reversed_str.resize(filtered_str.size());
    reverse_copy(filtered_str.begin(), filtered_str.end(),
                reversed_str.begin());
    return filtered_str == reversed_str;
}

int SolutionmyAtoi::myAtoi(string s) {
    auto temp = std::string();
    auto flag = true;
    for (auto ch : s) {
        if (ch == '-')
            flag = false;
        if (ch >= '0' && ch <= '9') 
        {
            if (ch == '0' && temp.size() != 0)
                temp += ch;
            else if (ch == '0' && temp.size() == 0)
                continue;
            else if (ch != '0')
                temp += ch;
        }
    }
    int result = 0;
    auto len = temp.size();
    for (auto ch : temp) {
        // result += ch;
        switch (ch) {
            case '0':
            break;            
            case '1':
                result += 1*std::pow(10, len-1); 
                len--;
            break;            
            case '2':                
                result += 2*std::pow(10, len-1); 
                len--;
            break;                
            case '3':
                result += 3*std::pow(10, len-1); 
                len--;            
            break;                
            case '4':                
                result += 4*std::pow(10, len-1); 
                len--;
            break;            
            case '5':                
                result += 5*std::pow(10, len-1); 
                len--;
            break;            
            case '6':                
                result += 6*std::pow(10, len-1); 
                len--;
            break;            
            case '7':                
                result += 7*std::pow(10, len-1); 
                len--;
            break;            
            case '8':                
                result += 8*std::pow(10, len-1); 
                len--;
            break;            
            case '9':                
                result += 9*std::pow(10, len-1); 
                len--;
            break;
        // case final:
        default:
            break;
        }
    }
    if (flag)
        return result;
    else {
        result *= -1;
        return result;
    }
};

int SolutionmyAtoi::myAtoi02(string s) {
    StateMachine Q;

    for (int i = 0; i < s.size() && Q.getState() != qd; ++i) {
        Q.transition(s[i]);
    }
    return Q.getInteger();
}

StateMachine::StateMachine() {
    currentState = q0;
    result = 0;
    sign = 1;
}

void StateMachine::transition(char& ch) {
    if (currentState == q0) {
        if (ch == ' ') {
            return;
        } else if (ch == '-' || ch == '+') {
            toStateQ1(ch);
        } else if (isdigit(ch)) {
            toStateQ2(ch - '0');
        } else {
            toStateQd();
        }
    } else if (currentState == q1 || currentState == q2) {
        if (isdigit(ch))
        {
            toStateQ2(ch - '0');
        } else {
            toStateQd();
        }
    }
}

int StateMachine::getInteger() {
    return sign * result;
}

State StateMachine::getState() {
    return currentState;
}

void StateMachine::toStateQ1(char& ch) {
    sign = (ch == '-') ? -1 : 1;
    currentState = q1;
}

void StateMachine::toStateQ2(int digit) {
    currentState = q2;
    appendDigit(digit);
}

void StateMachine::toStateQd() {
    currentState = qd;
}

void StateMachine::appendDigit(int& digit) {
    if ((result > INT_MAX / 10) || (result == INT_MIN / 10 && digit > INT_MAX % 10)) {
        if (sign == 1) {
            result = INT_MAX;
        } else {
            result = INT_MIN;
            sign = 1;
        }
        toStateQd();
    } else {
        result = result * 10 + digit;
    }
}

int SolutionmyAtoi::myAtoi01(string s) {
    int sign = 1;
    int result = 0;
    int index = 0;
    int n = s.size();

    while (index < n && s[index] == ' ') {
        index++;
    }

    if (index < n && s[index] == '-') {
        sign = -1;
        index++;
    } else if (index < n && s[index] == '+') {
        sign = 1;
        index++;
    }
    
    while (index < n && isdigit(s[index])) 
    {
        int digit = s[index] - '0';

        if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = 10 * result + digit;
        index++;
    }
    
    return sign * result;
}

void SolutionreverseString::reverseString(vector<char>& s) {
    for (size_t i = 0; i < s.size() / 2; i++)
    {
        auto temp = s[i];
        s[i] = s[s.size() - 1 - i];
        s[s.size() - 1 - i] = temp;
    }    
}

void SolutionreverseString::reverseString02(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        auto temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
    
}

vector<string> SolutionfindMissingRanges::findMissingRanges(vector<int>& nums, int lower, int upper) {
    std::vector<std::string> v;
    if (nums.empty())
    {
        return v;
    }
    if (nums.size() == upper + 1)
        return v;
    int left{};
    int right{};
    int pright{};
    std::string s{"->"};
    for(int i = lower; i <= upper; ++i)
    {
        if (std::find(nums.begin(), nums.end(), i-1) != nums.end() &&
            std::find(nums.begin(), nums.end(), i) == nums.end() && 
            std::find(nums.begin(), nums.end(), i+1) != nums.end())
            {
                v.push_back(std::to_string(i));
            }        
        
        if (std::find(nums.begin(), nums.end(), i-1) != nums.end() &&
            std::find(nums.begin(), nums.end(), i) == nums.end() && 
            std::find(nums.begin(), nums.end(), i+1) == nums.end())
            {
                left = i;
            }        
        
        if (std::find(nums.begin(), nums.end(), i-1) == nums.end() &&
            std::find(nums.begin(), nums.end(), i) == nums.end() && 
            std::find(nums.begin(), nums.end(), i+1) != nums.end())
            {
                right = i;
                if (right!=pright)
                {
                    auto temp = to_string(left);
                    temp.append(s);
                    temp.append(to_string(right));
                    v.push_back(temp);
                    pright = right;
                }
            }
    }
    return v;
}

vector<string> SolutionfindMissingRanges::findMissingRanges02(vector<int>& nums, int lower, int upper) {
    // string get_range(int start, int end)
    vector<string> result;
    int pre = lower - 1;
    
    for (int i = 0; i <= nums.size(); ++i)
    {
        int cur = (i==nums.size()? upper+1:nums[i]);
        if (cur-pre>=2)
        {
            result.push_back(get_range(pre+1, cur-1));
        }
        pre = cur;
    }
    return result;
}

string SolutionfindMissingRanges::get_range(int start, int end) {
    return start==end?to_string(start):to_string(start)+"->"+to_string(end);
}

MyHashMap::MyHashMap() {
    
}

void MyHashMap::put(int key, int value) {
    for (auto& t:p)
    {
        if (t.first == key)
        {
            t.second = value;
            break;
        }
    }

    auto temp = std::make_pair(key ,value);
    p.push_back(temp);
}

int MyHashMap::get(int key) {
    for (auto& t:p)
    {
        if (t.first == key)
            return t.second;
    }
    return -1;
}

void MyHashMap::remove(int key) {
    for (int i = 0; i< p.size(); ++i)
    {
        if (p[i].first == key)
        {
            p.erase(p.begin() + i);
            break;
        }
    }
}

MyHashMap02::MyHashMap02() {
    m_data.resize(m_size);
}

void MyHashMap02::put(int key, int value) {
    auto& list = m_data[key % m_size];
    for (auto & val: list)
    {
        if (val.first == key)
        {
            val.second = value;
            return;
        }
    }
    list.emplace_back(key, value);
}

int MyHashMap02::get(int key) {
    const auto& list = m_data[key % m_size];
    if (list.empty())
    {
        return -1;
    }

    for (const auto& val: list)
    {
        if (val.first == key)
        {
            return val.second;
        }
    }

    return -1;
}

void MyHashMap02::remove(int key) {
    auto& list = m_data[key % m_size];
    list.remove_if([key](auto n) {return n.first == key;});
    
}

bool Solution::containsDuplicate(vector<int>& nums) {
    std::vector<int> l;
    std::fill_n(std::back_inserter(l), nums.size(), 0);
    for (int i = 0; i < nums.size(); ++i)
    {
        if (std::find(nums.begin(), nums.end(), nums[i]) != nums.end())
        {
            l[i] += 1;
        }
    }

    int sum_of_elems = 0;

    std::for_each(l.begin(), l.end(), [&] (int n) {
        sum_of_elems += n;
    });

    if (sum_of_elems > nums.size())
    {
        return true;
    }
    return false;
}

int SolutionsingleNumber::singleNumber(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    vector<std::pair<int, int>> v;
    for (auto& p : nums)
    {
        auto temp = std::make_pair(p, 0);
        if (std::find(v.begin(), v.end(), temp) != v.end())
        {
            for (int i = 0; i<v.size(); ++i)
            {
                if (v[i].first == p)
                {
                    v[i].second += 1;
                    break;
                }
            }
        }
        else
        {
            v.push_back(temp);
        }
    }

    for (auto& p : v)
    {
        if (p.second == 0)
            return p.first;
    }
    return -1;
}

vector<int> Solutionintersection::intersection(vector<int>& nums1, vector<int>& nums2) {
    std::vector<int> v;
    std::unordered_set<int> my_set1;
    std::unordered_set<int> my_set2;
    for (auto& p : nums1)
    {
        my_set1.insert(p);
    }

    for (auto& p: nums2)
        my_set2.insert(p);

    if (my_set2.size() < my_set1.size())
    {
        for(const auto& p: my_set2)
        {
            auto search = my_set1.find(p);
            if (search != my_set1.end())
                v.push_back(p);
        }
    }
    else {
        for(const auto& p: my_set1)
        {
            auto search = my_set2.find(p);
            if (search != my_set2.end())
                v.push_back(p);
        }
    }
    return v;
}

bool SolutionisHappy::isHappy(int n) {
    int slow, fast;

    slow = fast = n;

    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while (slow != fast);

    if (slow == 1)
        return true;
    else return false;
}

int SolutionisHappy::isHappy02(int n) {
    auto len = std::to_string(n).size();

    int temp = 0;

    for (int i = len; i >= 0; i--)
    {
        if (i-1 != 0)
            temp += std::pow((n / ((i-1)*10)), 2);
        // else
        //     temp += std::pow(n/
    }


    std::cout << "temp = " << temp << std::endl;
    return temp;
}

int SolutionisHappy::digitSquareSum(int n) {
    int sum = 0, tmp;

    while (n){ 
        tmp = n % 10;
        sum += tmp*tmp;
        n /= 10;}
    return sum;
}

bool SolutionisHappy::isHappy03(int n) {
    std::unordered_set<int> temp{};
    // [n, temp](){ temp.find(n)};
    // auto search = example.find(2);
    while (n!=1&&(temp.find(n)!=temp.end())) {
        temp.insert(n);
        n = digitSquareSum(n);
    }
    return n == 1;
}

vector<int> Solutionintersection::intersection02(vector<int>& nums1, vector<int>& nums2) {
    auto tmp = std::unordered_set<int>(nums1.begin(), nums1.end());
    vector<int> res;

    for (auto a : nums2)
    {
        if (tmp.count(a))
        {
            res.push_back(a);
            tmp.erase(a);
        }
    }
    return res;
}

bool SolutionisIsomorphic::isIsomorphic(string s, string t) {
    auto flag = true;
    auto temp1 = get_map(s);
    auto temp2 = get_map(t);

    auto f = [](std::unordered_map<char, int> p) {
        int result = 0;
        for (auto& t: p)
            result += t.second;
        return result;
    };
    if (temp1.size() != temp2.size())
        // return false;
        flag = false;
    else if (f(temp1)!=f(temp2))
        // return false;
        flag = false;

    // for (int i = 0; i < temp1.size(); ++i)
    // {
    //     if (temp1[i].second )

    // }

    for (auto& ttt: temp1)
    {
        if (temp1.count(ttt.first) != temp2.count(ttt.first))
            flag = false;
    }
    return flag;
}

bool SolutionisIsomorphic::isIsomorphic02(string s, string t) {
    if (s.size() != t.size())
        return false;
    else {    
        std::unordered_map<char, char> temp1;
        std::unordered_map<char, char> temp2;
        for (size_t i = 0; i < s.size(); ++i)
        {
            if (!temp1.empty() && (temp1.find(s[i]) != temp1.end()))
            {
                auto a1 = temp1.find(s[i]);
                if (a1->second != t[i])
                    return false;
            }
            
            if (!temp2.empty() && (temp2.find(t[i]) != temp2.end()))
            {
                auto a1 = temp2.find(t[i]);
                if (a1->second != s[i])
                    return false;
            }
            temp1.emplace(s[i], t[i]);
            temp2.emplace(t[i], s[i]);
        }
    }
    return true;
}
 
std::unordered_map<char, int> SolutionisIsomorphic::get_map(string t) {
    std::unordered_map<char, int> tmp;
    for (auto& p: t)
    {
        if (!tmp.empty())
        {
            for (auto& tt: tmp)
            {
                if (tt.first == p)
                {
                    tt.second += 1;
                    break;
                }
            }
            tmp.emplace(p, 0);
        }
    }
    return tmp;
}

// class SolutionaddDigits {
// public:
//     int addDigits(int num);
int SolutionaddDigits::addDigits(int num)
{
    int digital_root = 0;
    while (num > 0)
    {
        digital_root += num % 10;
        num = num / 10;

        if (num == 0 && digital_root > 9)
        {
            num = digital_root;
            digital_root = 0;
        }
    }
    return digital_root;
}


// class SolutionfindRestaurant {
// public:
//     vector<string> findRestaurant(vector<string>& list1, vector<string>& list2);

vector<string> SolutionfindRestaurant::findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> result{};
    std::unordered_map<string, int> temp1;
    std::unordered_map<string, int> temp2;
    for (int i = 0; i<list1.size(); ++i)
    {
        temp1.emplace(list1[i], i);
    }
    for (int i = 0; i<list2.size(); ++i)
    {
        temp2.emplace(list2[i], i);
    }
    if (temp1.size() > temp2.size())
    {
        int index = temp1.size() + 1;

        for (auto& p1: temp1)
        {
            if (temp2.find(p1.first) != temp2.end())
            {
                if (index > p1.second)
                    index = p1.second;
            }
        }
        for (auto& p2: temp1)
        {     
            if (temp2.find(p2.first)->second == index)
            {
                result.push_back(p2.first);
            }
        }

    } else {
        int index = temp2.size() + 1;
        for (auto& p: temp2)
        {
            if (temp1.find(p.first) != temp1.end())
            {
                if (index > p.second)
                    index = p.second;
            }
        }
        for (auto& p: temp2)
        {     
            if (temp2.find(p.first)->second == index)
            {
                result.push_back(p.first);
            }
        }
    }
    return result;
}

vector<string> SolutionfindRestaurant::findRestaurant02(vector<string>& list1, vector<string>& list2) {
    std::unordered_map<string, int> temp1;
    std::unordered_map<string, int> temp2;

    for (int i = 0; i < list1.size(); ++i)
    {
        if (std::find(list2.begin(), list2.end(), list1[i]) != list2.end())
        {
            temp1.emplace(list1[i], i);
        }
    }
    for (int i = 0; i < list2.size(); ++i)
    {
        if (std::find(list1.begin(), list1.end(), list2[i]) != list1.end())
        {
            temp2.emplace(list2[i], temp1[list2[i]] + i);
        }
    }

    std::vector<std::string> final_result;
    if (temp2.size() == 1)
    {    
        for (auto& list : temp2)
            final_result.push_back(list.first);
    } else {
        int lower_index = list1.size() + list2.size() - 1;
        for (auto& p : temp2)
        {
            if (p.second < lower_index)
                lower_index = p.second;
        }
        // std::vector<std::string> final_result;
        for (auto& p : temp2)
        {
            if (p.second == lower_index)
                final_result.push_back(p.first);
        }
    }
    return final_result;
}


// class SolutionfirstUniqChar {
// public:
//     int firstUniqChar(string s);
int SolutionfirstUniqChar::firstUniqChar(string s)
{
    std::unordered_map<char, int> temp;
    for (int i = 0; i < s.size(); ++i)
    {
        if (temp.find(s[i]) != temp.end())
        {
            temp[s[i]] += 1;
        } else {
            temp.emplace(s[i], 1);
        }
    }
    for (int i = 0; i < s.size(); ++i)
    {
        if (temp[s[i]] == 1)
            return i;
    }
    return -1;
}

vector<int> SolutionintersectII::intersect(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_map<char, int> temp;
    std::vector<int> result;
    for (const auto& p : nums1)
    {
        if (temp.find(p) != temp.end())
        {
            temp[p] += 1;
        } else {
            temp.emplace(p, 1);
        }
    }

    for (const auto& p : nums2)
    {
        if (temp.find(p) != temp.end())
        {
            if (temp[p] > 0)
            {
                result.push_back(p);
                temp[p] -= 1;
            }
        }
    }
    return result;
}

vector<int> SolutionintersectII::intersect02(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size())
    {
        return intersect02(nums2, nums1);
    }

    unordered_map<int, int> m;
    for (auto n: nums1)
    {
        ++m[n];
    }
    int k = 0;
    for (auto n: nums2)
    {
        auto it = m.find(n);
        if (it != end(m) && --it->second >= 0)
        {
            nums1[k++] = n;
        }
    }
    return vector(begin(nums1), begin(nums1) + k);
}

vector<int> SolutionintersectII::intersect03(vector<int>& nums1, vector<int>& nums2) {
    sort(begin(nums1), end(nums1));
    sort(begin(nums2), end(nums2));
    int i = 0, j = 0, k = 0;
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            ++i;
        } else if (nums1[i] > nums2[j])
            ++j;
        else {
            nums1[k++] = nums1[i++];
            ++j;
        }
    }
    return vector<int>(begin(nums1), begin(nums1) + k);
}

// bool SolutioncontainsNearbyDuplicate::containsNearbyDuplicate(vector<int>& nums, int k) {
//     std::unordered_map<int, int> temp;
//     // std::

//     for (auto& p : nums)
//     {
//         if (temp.find(p) != temp.end())
//             temp[p] += 1;
//         else
//             temp.emplace(p, 0);
//     }

//     for (auto& p : temp)
//     {
//         if (p.second == 1)
//         {
//             auto num_index_first = std::find(nums.begin(), nums.end(), p.first);
//             auto num_index_second = std::find(num_index_first + 1, nums.end(), p.first);
//             if (std::distance(num_index_second, num_index_first) <= k)
//                 return true;
//             else
//                 return false;
//         }
//     }
//     return false;
// }

bool SolutioncontainsNearbyDuplicate::containsNearbyDuplicate02(vector<int>& nums, int k) {
    unordered_set<int> s;
    if (k <= 0) 
        return false;
    if (k >= nums.size()) 
        k = nums.size() -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k) 
            s.erase(nums[i - k - 1]);
        if (s.find(nums[i]) != s.end())
            return true;
        s.insert(nums[i]);
    }

    return false;
}