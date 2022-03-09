#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

/*
思路：快慢指针
    我们定义两个指针，一个是快指针，一个是慢指针。
    快指针每次走两部，慢指针每次走一步
    因为快指针到空节点的速度比慢指针快一倍，当快指针走到空时慢指针也就走了整个链表二分之一的路程，
    而此时返回慢指针的地址就是该链表的中间节点。
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