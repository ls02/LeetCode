#include <iostream>

using namespace std;

struct ListNode
{
	ListNode* next;
	int val;
};

/*
思路：快慢指针
    创建两个指针变量，一个是快指针一个是慢指针。
    快指针一次走两步，慢指针一次走一步如果是带环链表那么一定会相遇因为快指针每次走n-1步不会错过满指针。
    如果遍历完说明不是带环链表返回false
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