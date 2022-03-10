#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

/*
˼·������
    ��һ��prev������ǰһ������������ÿ�α���ʱ����ı䵱ǰ�ڵ����һ�����ڸı䵱ǰ�ڵ����һ���ڵ�ʱ����һ��next���б���
    ��ָ�������prev��ָ���ָ��ǰ�ڵ�ֱ�������������
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //�жϿձ�
        if (nullptr == head)
        {
            return nullptr;
        }

        ListNode* cur = head;
        ListNode* prev = nullptr;

        //����
        while (nullptr != cur)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }
};