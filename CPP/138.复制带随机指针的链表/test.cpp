#include <iostream>

using namespace std;

struct Node
{
    Node* next;
    Node* random;
    int val;
};

/*
思路：迭代+节点拆分
    建立链接：
            遍历原链表并在原链表内插入一个copyNode该copyNode和原链表的元素值是相同的，
    拷贝random：
                遍历建立链接后的链表，并对copyNode的random进行建立链接，由于前面和原链表建立了链接cur->random->next就是copyNode想要的random节点。
    分离copyNode：
                    遍历原链表分离出copyNode，用一个哨兵位节点来建立copyHead，通过遍历把copyNode全部链接道coypHead后面。
                
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head)
        {
            return nullptr;
        }

        //建立链接
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

        //拷贝random
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

        //分离
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