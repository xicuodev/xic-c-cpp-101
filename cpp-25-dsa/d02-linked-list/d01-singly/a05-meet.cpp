// 判断两个单链表是否相交，返回相交节点的值
// 思路：早晚指针，求两个链表长度差d
//       早指针指向较长的链表，先走d步
//       晚指针指向较短的链表
#include "SinglyLinkedListMock.hpp"

typedef SinglyLinkedList::Node Node;

bool WhetherMeet(Node *headNode1, Node *headNode2, Node *&meetNode)
{
    int size1 = 0, size2 = 0;
    Node *p = headNode1, *q = headNode2;
    while (p != nullptr)
    {
        p = p->GetNextNode();
        size1++;
    }
    while (q != nullptr)
    {
        q = q->GetNextNode();
        size2++;
    }

    p = headNode1;
    q = headNode2;
    if (size1 < size2)
    {
        Node *temp = p;
        p = q;
        q = temp;
    }
    int deltaSize = abs(size1 - size2);
    while (deltaSize-- > 0)
    {
        p = p->GetNextNode();
    }
    while (q != nullptr)
    {
        if (p == q)
        {
            meetNode = p;
            return true;
        }
        p = p->GetNextNode();
        q = q->GetNextNode();
    }
    meetNode = nullptr;
    return false;
}

int main()
{
    Node *node4 = new Node(18);
    Node *node3 = new Node(32, node4);
    Node *node2 = new Node(67, node3);
    Node *node1 = new Node(25, node2);
    Node *head1 = new Node(0, node1);

    Node *node5 = new Node(23, node3);
    Node *head2 = new Node(0, node5);

    Node *meetNode = nullptr;
    bool whetherMeet = WhetherMeet(head1, head2, meetNode);
    if (whetherMeet)
    {
        std::cout << "相交, 交点数据=" << meetNode->GetData() << std::endl;
    }
    else
    {
        std::cout << "不相交" << std::endl;
    }
}