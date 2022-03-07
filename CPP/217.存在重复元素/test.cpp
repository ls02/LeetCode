#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
思路：迭代
    先对nums进行排序，当排好序之后如果有出现两个及以上的数字，那么它们会挨在一起
    我们只需判断两个相邻元素是否想等如果相等说明出现了两个这时只需返回true即可
    如果遍历完了整个数组还没返回说明该数组没有过两个及以上的相同元素。
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for (i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                return true;
            }
        }

        return false;
    }
};