#include <vector>
#include <iostream>

using namespace std;

/*
思路：虚拟数组
    我们直接把nums1数组当成一个新创建的数组，把nums1和nums2内存储的元素进行比较
    把较大的值从后往前插入道nums1数组后面，当nums1或nums2为空时就停止插入
    如果停止之后还有元素没插入进nums1内的话，我们单独处理。
    如果是nums2没插入完就需要处理，而如果是nums1没插入完就不需要处理，因为nums1本身就是虚拟数组而它的值也不用动，就算动也是原地挪。
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