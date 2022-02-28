#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v1;

        int i = 0;
        for (i = 0; i < nums.size() - 1; i++)
        {
            int j = 0;
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    v1.push_back(i);
                    v1.push_back(j);

                    return v1;
                }
            }
        }

        return v1;
    }
};