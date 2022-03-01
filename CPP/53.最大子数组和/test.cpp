#include <iostream>
#include <vector>

using namespace std;

/*
思路：动态规划
    第一步：用prev变量来表示前i-1个元素之和，max变量表示当前数组的元素之和的最大值。
    第二步：如果前i-1个之和小于当前第i个元素，那么前i-1个元素之和一定不是最大值，这时需要重新累加以当前第i个元素为起点继续累加
            如果前i-1个之和大于当前第i个元素，那么就把当前第i个元素和前i-1个元素相加。
    第三步：更新当前最大值
    
*/
class Solution {
public:

    int Max(int x, int y)
    {
        return x > y ? x : y;
    }

    int maxSubArray(vector<int>& nums) {
        int prev = 0;
        int max = nums[0];

        int i = 0;
        for (i = 0; i < nums.size(); i++)
        {
            //判断是前i个元素之和大还是当前元素大
            //如果小于当前元素，那么前i个元素之和就遗弃，当前元素成为新的连续元素之和
            //如果大于当前元素那么前i个元素之和就再加上当前元素。
            prev = Max(prev + nums[i], nums[i]);
            //更新当前最大的元素之和
            max = Max(prev, max);
        }

        return max;
    }
};