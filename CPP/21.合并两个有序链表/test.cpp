#include <iostream>

using namespace std;

struct ListNode
{
    ListNode* next;
    int val;
};

/*
思路：迭代
    创建一个哨兵位节点作为合并后的新节点，比较两个链表小的节点插入到哨兵位后面直到一方为空表
    当一方为空表另一方一定不为空表，这时直接插入到哨兵位后面即可
    当完成以上操作释放哨兵位节点，返回合并后的新节点。
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //如果链表为空就返回nullptr
        if (nullptr == list1 && nullptr == list2)
        {
            return nullptr;
        }

        //创建一个哨兵位
        ListNode* newHead = new ListNode;
        ListNode* prev = newHead;

        //进行迭代直到一方链表为空停止
        while (nullptr != list1 && nullptr != list2)
        {
            //把较下值的节点插入prev后面
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

        //一方为空表那么另一方直接连上去
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