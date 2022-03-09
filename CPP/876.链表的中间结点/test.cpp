#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

/*
˼·������ָ��
    ���Ƕ�������ָ�룬һ���ǿ�ָ�룬һ������ָ�롣
    ��ָ��ÿ������������ָ��ÿ����һ��
    ��Ϊ��ָ�뵽�սڵ���ٶȱ���ָ���һ��������ָ���ߵ���ʱ��ָ��Ҳ�����������������֮һ��·�̣�
    ����ʱ������ָ��ĵ�ַ���Ǹ�������м�ڵ㡣
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (nullptr != fast && nullptr != fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};