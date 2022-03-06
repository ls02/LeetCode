#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
};

/*
˼·������
    ��������������¼�����ȣ�������������ó��������߲�ಽ��
    ��������ͬʱ��������˵���й����ڵ㣬��������껹û���˵��û�й����ڵ㷵��nullptr
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;

        //����������ĳ���
        while (nullptr != curA)
        {
            curA = curA->next;
            lenA++;
        }
        while (nullptr != curB)
        {
            curB = curB->next;
            lenB++;
        }

        curA = headA;
        curB = headB;
        int n = abs(lenA - lenB);
        //�����߲�ಽ
        if (lenA > lenB)
        {
            while (n)
            {
                curA = curA->next;
                n--;
            }
        }
        else
        {
            while (n)
            {
                curB = curB->next;
                n--;
            }
        }

        //ͬʱ�ߣ�������˵�����й����ڵ㣬��������겻���˵��û�й����ڵ�
        while (nullptr != curA)
        {
            if (curA == curB)
            {
                return curA;
            }

            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};