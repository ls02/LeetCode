#include <iostream>

using namespace std;

struct Node
{
    Node* next;
    Node* random;
    int val;
};

/*
˼·������+�ڵ���
    �������ӣ�
            ����ԭ������ԭ�����ڲ���һ��copyNode��copyNode��ԭ�����Ԫ��ֵ����ͬ�ģ�
    ����random��
                �����������Ӻ����������copyNode��random���н������ӣ�����ǰ���ԭ������������cur->random->next����copyNode��Ҫ��random�ڵ㡣
    ����copyNode��
                    ����ԭ��������copyNode����һ���ڱ�λ�ڵ�������copyHead��ͨ��������copyNodeȫ�����ӵ�coypHead���档
                
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head)
        {
            return nullptr;
        }

        //��������
        Node* cur = head;
        while (nullptr != cur)
        {
            Node* next = cur->next;
            Node* copyNode = new Node;
            copyNode->val = cur->val;
            cur->next = copyNode;
            copyNode->next = next;
            cur = next;
        }

        //����random
        cur = head;
        while (nullptr != cur)
        {
            Node* copyNode = cur->next;
            Node* random = cur->random;
            if (nullptr == random)
            {
                copyNode->random = nullptr;
            }
            else
            {
                copyNode->random = random->next;
            }

            cur = copyNode->next;
        }

        //����
        Node* copyHead = new Node(-1);
        Node* copyTail = copyHead;
        cur = head;
        while (nullptr != cur)
        {
            Node* copyNode = cur->next;
            copyTail->next = copyNode;
            cur->next = copyNode->next;
            cur = copyNode->next;
            copyTail = copyTail->next;
        }

        Node* temp = copyHead;
        copyHead = copyHead->next;
        delete temp;

        return copyHead;
    }
};