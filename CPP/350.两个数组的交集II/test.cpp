#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
˼·������+˫ָ��
    �����ȶ��������������ź�����ٶ����������ÿһ��Ԫ�����αȽϡ�
    �������Ⱦ�С���������ߡ�
    �����Ⱦ�һ�������ߵ�ͬʱ�ѵ�ǰԪ�ز������������
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