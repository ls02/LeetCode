struct ListNode
{
    ListNode* next;
    int val;
};

/*
思路：双链表
    我们创建两个哨兵位头节点，lesser存放小于x的节点，greater存放大于等于x的节点。
    用cur对原链表进行遍历的同时，分离出小于x的节点。
    分离完后再把greater链接道lesser后面（注意：链接前一定要把greater最后一个节点的下一个置空，否则链表可能会成环）。
    释放创建的两个哨兵位，并返回链接后的节点

*/

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        //创建两个哨兵位来完成
        ListNode* lesserHead = new ListNode;
        ListNode* lesserTail = lesserHead;
        ListNode* greaterHead = new ListNode;
        ListNode* greaterTail = greaterHead;

        //对原链表进行分离
        ListNode* cur = pHead;
        while (nullptr != cur)
        {
            if (cur->val < x)
            {
                lesserTail->next = cur;
                lesserTail = lesserTail->next;
            }
            else
            {
                greaterTail->next = cur;
                greaterTail = greaterTail->next;
            }

            cur = cur->next;
        }

        //防止链表成环
        greaterTail->next = nullptr;
        //链接
        lesserTail->next = greaterHead->next;

        //释放哨兵位
        ListNode* temp = lesserHead;
        lesserHead = lesserHead->next;
        delete temp;
        delete greaterHead;

        //返回链接后的链表
        return lesserHead;
    }
};