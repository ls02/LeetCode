#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
思路：排序+双指针
    我们先对两个数组排序，排好序后再对两个数组的每一个元素依次比较。
    如果不相等就小的先往后走。
    如果相等就一起往后走的同时把当前元素插入道新数组内
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> v1;

        int sz1 = 0;
        int sz2 = 0;
        while (sz1 < nums1.size() && sz2 < nums2.size())
        {
            if (nums1[sz1] < nums2[sz2])
            {
                sz1++;
            }
            else if (nums1[sz1] > nums2[sz2])
            {
                sz2++;
            }
            else
            {
                v1.push_back(nums1[sz1]);
                sz1++;
                sz2++;
            }
        }

        return v1;
    }
};