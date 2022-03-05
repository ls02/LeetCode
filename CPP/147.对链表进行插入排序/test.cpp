#include <iostream>
#include <string>

using namespace std;

struct ListNode
{
	ListNode* next;
	int val;
};

/*
˼·����ǰ�����Ҳ���ڵ�
    �����Ȱѵ�һ���ڵ㵱����������������cur����ڶ����ڵ��һ���ڵ��ٺͺ���Ľڵ�Ͽ������γ���������
    ����cur��
            ���sortHead�ڵĽڵ��cur��Ļ�˵����λ�þ���curҪ����Ľڵ���������ͨ��prev����cur�����µ�����
            ͷ�壺
                    prev���Ϊ��˵����ͷ�壬��������ֻ��cur->nextָ��sortHead��cur��Ϊ�µ����������ͷ�ڵ�
            ����λ�ò壺
                        ����ֻ����prev->nextָ��cur��cur->nextָ��sortCur��������������
*/

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (nullptr == head || nullptr == head->next)
        {
            return head;
        }

        //���룬��һ���ڵ㵱���������
        ListNode* sortHead = head;
        ListNode* cur = head->next;
        sortHead->next = nullptr;

        //����cur����
        while (nullptr != cur)
        {
            ListNode* sortCur = sortHead;
            ListNode* prev = nullptr;

            //�ҵ�����λ��
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

            //����cur��next
            ListNode* next = cur->next;

            //�ж���ͷ�廹�������
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