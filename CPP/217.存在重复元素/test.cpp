#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
˼·������
    �ȶ�nums�������򣬵��ź���֮������г������������ϵ����֣���ô���ǻᰤ��һ��
    ����ֻ���ж���������Ԫ���Ƿ����������˵��������������ʱֻ�践��true����
    ������������������黹û����˵��������û�й����������ϵ���ͬԪ�ء�
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