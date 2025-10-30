// 有序单链表合并
// 思路：双指针+辅助指针
#include "SinglyLinkedListMock.hpp"

typedef SinglyLinkedList::Node Node;

void Merge(SinglyLinkedList &list1, SinglyLinkedList &list2)
{
    Node *p = list1.GetHeadNode()->GetNextNode();
    Node *q = list2.GetHeadNode()->GetNextNode();
    // 辅助指针，指向已合并的链表的末尾节点
    Node *last = list1.GetHeadNode();
    list2.GetHeadNode()->SetNextNode(nullptr);
    list2.~SinglyLinkedList();
    while (p != nullptr && q != nullptr)
    {
        if (p->GetData() <= q->GetData())
        {
            last->SetNextNode(p);
            last = p;
            p = p->GetNextNode();
            continue;
        }
        else
        {
            last->SetNextNode(q);
            last = q;
            q = q->GetNextNode();
            continue;
        }
    }
    if (p != nullptr)
    {
        last->SetNextNode(p);
    }
    else
    {
        last->SetNextNode(q);
    }
}

int main()
{
    SinglyLinkedList &list1 = GetMockOrderedSinglyLinkedList(12);
    SinglyLinkedList &list2 = GetMockOrderedSinglyLinkedList(8, 6);
    list1.SelfShow();
    list2.SelfShow();
    Merge(list1, list2);
    list1.SelfShow();
}