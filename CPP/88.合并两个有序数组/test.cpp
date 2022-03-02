#include <vector>
#include <iostream>

using namespace std;

/*
˼·����������
    ����ֱ�Ӱ�nums1���鵱��һ���´��������飬��nums1��nums2�ڴ洢��Ԫ�ؽ��бȽ�
    �ѽϴ��ֵ�Ӻ���ǰ�����nums1������棬��nums1��nums2Ϊ��ʱ��ֹͣ����
    ���ֹ֮ͣ����Ԫ��û�����nums1�ڵĻ������ǵ�������
    �����nums2û���������Ҫ�����������nums1û������Ͳ���Ҫ������Ϊnums1��������������������ֵҲ���ö������㶯Ҳ��ԭ��Ų��
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int sz = m + n - 1;
        int sz1 = m - 1;
        int sz2 = n - 1;

        while (sz2 >= 0 && sz1 >= 0)
        {
            if (nums1[sz1] > nums2[sz2])
            {
                nums1[sz--] = nums1[sz1--];
            }
            else
            {
                nums1[sz--] = nums2[sz2--];
            }
        }

        while (sz2 >= 0)
        {
            nums1[sz--] = nums2[sz2--];
        }
    }
};