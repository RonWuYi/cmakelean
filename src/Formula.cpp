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
