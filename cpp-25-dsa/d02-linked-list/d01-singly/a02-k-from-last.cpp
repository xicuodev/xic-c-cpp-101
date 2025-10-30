// 单链表倒数第k个节点
// 思路：早晚指针，早指针先走k步
#include "SinglyLinkedListMock.hpp"

typedef SinglyLinkedList::Node Node;

Node *GetKthNodeFromLast(int k, SinglyLinkedList &list)
{
    Node *fastPtr = list.GetHeadNode();
    Node *slowPtr = list.GetHeadNode();
    for (int i = 0; i < k; i++)
    {
        fastPtr = fastPtr->GetNextNode();
        if (fastPtr == nullptr)
        {
            return nullptr;
        }
    }
    while (fastPtr != nullptr)
    {
        slowPtr = slowPtr->GetNextNode();
        fastPtr = fastPtr->GetNextNode();
    }
    return slowPtr;
}

int main()
{
    SinglyLinkedList &list = GetMockRandomSinglyLinkedList();
    list.SelfShow();
    int k = 3;
    Node *kthNode = GetKthNodeFromLast(k, list);
    if (kthNode == nullptr)
    {
        std::cout << "没有这样的节点：倒数第 " << k << "个节点" << std::endl;
    }
    std::cout << "倒数第 " << k << " 个节点的值：" << kthNode->GetData() << std::endl;
}