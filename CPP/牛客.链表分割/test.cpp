struct ListNode
{
    ListNode* next;
    int val;
};

/*
˼·��˫����
    ���Ǵ��������ڱ�λͷ�ڵ㣬lesser���С��x�Ľڵ㣬greater��Ŵ��ڵ���x�Ľڵ㡣
    ��cur��ԭ������б�����ͬʱ�������С��x�Ľڵ㡣
    ��������ٰ�greater���ӵ�lesser���棨ע�⣺����ǰһ��Ҫ��greater���һ���ڵ����һ���ÿգ�����������ܻ�ɻ�����
    �ͷŴ����������ڱ�λ�����������Ӻ�Ľڵ�

*/

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        //���������ڱ�λ�����
        ListNode* lesserHead = new ListNode;
        ListNode* lesserTail = lesserHead;
        ListNode* greaterHead = new ListNode;
        ListNode* greaterTail = greaterHead;

        //��ԭ������з���
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

        //��ֹ����ɻ�
        greaterTail->next = nullptr;
        //����
        lesserTail->next = greaterHead->next;

        //�ͷ��ڱ�λ
        ListNode* temp = lesserHead;
        lesserHead = lesserHead->next;
        delete temp;
        delete greaterHead;

        //�������Ӻ������
        return lesserHead;
    }
};