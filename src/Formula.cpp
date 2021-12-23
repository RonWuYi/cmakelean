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

// int EasySolution::maxSubArray(vector<int>& nums) {
//     if (nums.size() <= 1) 
//     {
//         return nums[0];
//     }
//     else
//     {
//         vector<int> temp;
//         int max = min_element(nums);
//         for (size_t i = 0; i < nums.size(); ++i)
//         {
//             /* code */
//             temp.push_back(nums[i]);
//             if (sum(temp) > 0 && sum(temp) > max) 
//             {
//                 max = sum(temp);
//             }
//             else if (sum(temp) <= 0) 
//             {
//                 temp.clear();
//             }
//         }
//         return max;
//     }
// }


// int EasySolution::maxSubArray(vector<int>& nums) {
//     int sum = 0;
//     int len = nums.size();
//     // int max = std::min_element(nums.begin(), nums.end());

//     if (len <= 1) 
//     {
//         return nums[0];
//     }
//     else
//     {
//         for (size_t i = 0; i < nums.size(); ++i)
//         {
//             for (size_t j = i; j < nums.size(); ++j)
//             {
//                 sum += nums[j];
//                 if (sum > max) 
//                 {
//                     max = sum;
//                 }
//             }
//         }
//         return max;
//     }
// }