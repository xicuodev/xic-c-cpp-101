// 单链表逆序
// 思路：p指针遍历单链表，把p指针指向的节点按头插法插入到上面的链表中
#include "SinglyLinkedListMock.hpp"

typedef SinglyLinkedList::Node Node;

void ReverseList(SinglyLinkedList &list)
{
    Node *head = list.GetHeadNode();
    Node *p = head->GetNextNode();
    head->SetNextNode(nullptr);

    while (p != nullptr)
    {
        list.InsertHead(p->GetData());
        p = p->GetNextNode();
    }
}

int main()
{
    SinglyLinkedList &list = GetMockRandomSinglyLinkedList();
    list.SelfShow();
    ReverseList(list);
    list.SelfShow();
}