#include "Formula.h"

int Formula::bla(int arg1) {
    return arg1 * 2;
}

int EasySolution::maxSubArray(vector<int>& nums) {
    int sum = 0;
    int len = nums.size() - 1;
    int max = 0;

    if (len <= 1) 
    {
        return nums[0];
    }
    else
    {
        while (len > 0) 
        {
            for (size_t i = len; i < (nums.size() -1); i++)
            {
                sum += nums[i];
            }
            if (sum > max) 
            {
                max = sum;
            }
            len -= 1;
        }
        return max;
    }
}