#include <iostream>
#include <vector>

using namespace std;

/*
˼·����̬�滮
    ��һ������prev��������ʾǰi-1��Ԫ��֮�ͣ�max������ʾ��ǰ�����Ԫ��֮�͵����ֵ��
    �ڶ��������ǰi-1��֮��С�ڵ�ǰ��i��Ԫ�أ���ôǰi-1��Ԫ��֮��һ���������ֵ����ʱ��Ҫ�����ۼ��Ե�ǰ��i��Ԫ��Ϊ�������ۼ�
            ���ǰi-1��֮�ʹ��ڵ�ǰ��i��Ԫ�أ���ô�Ͱѵ�ǰ��i��Ԫ�غ�ǰi-1��Ԫ����ӡ�
    �����������µ�ǰ���ֵ
    
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
            //�ж���ǰi��Ԫ��֮�ʹ��ǵ�ǰԪ�ش�
            //���С�ڵ�ǰԪ�أ���ôǰi��Ԫ��֮�;���������ǰԪ�س�Ϊ�µ�����Ԫ��֮��
            //������ڵ�ǰԪ����ôǰi��Ԫ��֮�;��ټ��ϵ�ǰԪ�ء�
            prev = Max(prev + nums[i], nums[i]);
            //���µ�ǰ����Ԫ��֮��
            max = Max(prev, max);
        }

        return max;
    }
};