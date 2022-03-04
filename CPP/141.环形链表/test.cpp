#include <iostream>

using namespace std;

struct ListNode
{
	ListNode* next;
	int val;
};

/*
˼·������ָ��
    ��������ָ�������һ���ǿ�ָ��һ������ָ�롣
    ��ָ��һ������������ָ��һ����һ������Ǵ���������ôһ����������Ϊ��ָ��ÿ����n-1����������ָ�롣
    ���������˵�����Ǵ���������false
*/

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (nullptr == head)
        {
            return false;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while (nullptr != fast && nullptr != fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
            {
                return true;
            }
        }

        return false;
    }
};