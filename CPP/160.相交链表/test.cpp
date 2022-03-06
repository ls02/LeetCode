#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
};

/*
思路：迭代
    先用两个变量记录链表长度，求出长的链表让长的链表走差距步。
    两个链表同时走如果相等说明有公共节点，如果遍历完还没相等说明没有公共节点返回nullptr
*/

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;

        //求两个链表的长度
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
        //长的走差距步
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

        //同时走，如果相等说明是有公共节点，如果遍历完不相等说明没有公共节点
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