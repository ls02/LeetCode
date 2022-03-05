#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
	ListNode* next;
	int val;
};

/*
思路：从前往后找插入节点
    我们先把第一个节点当成是有序链表，并让cur保存第二个节点第一个节点再和后面的节点断开链接形成两个链表。
    遍历cur：
            如果sortHead内的节点比cur大的话说明该位置就是cur要插入的节点这是我们通过prev来和cur建立新的链接
            头插：
                    prev如果为空说明是头插，这是我们只需cur->next指向sortHead后cur成为新的有序链表的头节点
            任意位置插：
                        我们只需用prev->next指向cur而cur->next指向sortCur即可完成任意插入
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        //分离，第一个节点当成是有序的
        ListNode* sortHead = head;
        ListNode* cur = head->next;
        sortHead->next = nullptr;

        //遍历cur插入
        while (nullptr != cur)
        {
            ListNode* sortCur = sortHead;
            ListNode* prev = nullptr;

            //找到插入位置
            while (nullptr != sortCur)
            {
                if (sortCur->val > cur->val)
                {
                    break;
                }
                else
                {
                    prev = sortCur;
                    sortCur = sortCur->next;
                }
            }

            //保存cur的next
            ListNode* next = cur->next;

            //判断是头插还是任意插
            if (nullptr == prev)
            {
                cur->next = sortHead;
                sortHead = cur;
            }
            else
            {
                prev->next = cur;
                cur->next = sortCur;
            }

            cur = next;
        }

        return sortHead;
    }
};