#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
};

/*
思路：迭代
    用一个prev来保存前一个，遍历链表每次遍历时都会改变当前节点的下一个，在改变当前节点的下一个节点时会用一个next进行保存
    当指向更改完prev的指向就指向当前节点直到遍历完该链表。
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //判断空表
        if (nullptr == head)
        {
            return nullptr;
        }

        ListNode* cur = head;
        ListNode* prev = nullptr;

        //遍历
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