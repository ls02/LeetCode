#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
};

/*
˼·������
    ����һ���ڱ�λ�ڵ���Ϊ�ϲ�����½ڵ㣬�Ƚ���������С�Ľڵ���뵽�ڱ�λ����ֱ��һ��Ϊ�ձ�
    ��һ��Ϊ�ձ���һ��һ����Ϊ�ձ���ʱֱ�Ӳ��뵽�ڱ�λ���漴��
    ��������ϲ����ͷ��ڱ�λ�ڵ㣬���غϲ�����½ڵ㡣
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //�������Ϊ�վͷ���nullptr
        if (nullptr == list1 && nullptr == list2)
        {
            return nullptr;
        }

        //����һ���ڱ�λ
        ListNode* newHead = new ListNode;
        ListNode* prev = newHead;

        //���е���ֱ��һ������Ϊ��ֹͣ
        while (nullptr != list1 && nullptr != list2)
        {
            //�ѽ���ֵ�Ľڵ����prev����
            if (list1->val > list2->val)
            {
                prev->next = list2;
                list2 = list2->next;
            }
            else
            {
                prev->next = list1;
                list1 = list1->next;
            }

            prev = prev->next;
        }

        //һ��Ϊ�ձ���ô��һ��ֱ������ȥ
        if (nullptr != list1)
        {
            prev->next = list1;
        }
        else
        {
            prev->next = list2;
        }

        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;

        return newHead;
    }
};