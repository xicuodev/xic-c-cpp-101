// 单链表是否存在环？找出环的入口节点
// 思路：快慢指针，快指针每次走2步，慢指针每次走1步
//      让快指针套圈遇上慢指针
// 找出环的入口节点：
//   设链表方向为正方向，x=头节点到入口节点的正向距离，
//   y=入口节点到相遇节点的正向距离，
//   a=相遇节点到入口节点的正向距离
//   fast遍历的节点数量 = 2*slow遍历的节点数量
//   x+y+a+y=x+y
//   a=x
// 设p1指向头节点，p2指向相遇节点，每次各走1步，它们相遇时就是入口节点
#include "SinglyLinkedListMock.hpp"

typedef SinglyLinkedList::Node Node;

bool HasCircle(Node *headNode, Node *&entryNode)
{
    Node *fast = headNode;
    Node *slow = headNode;
    while (fast != nullptr && fast->GetNextNode() != nullptr)
    {
        fast = fast->GetNextNode()->GetNextNode();
        slow = slow->GetNextNode();
        if (slow == fast)
        {
            // 找环的入口
            fast = headNode;
            while (fast != slow)
            {
                fast = fast->GetNextNode();
                slow = slow->GetNextNode();
            }
            entryNode = fast;
            return true;
        }
    }
    return false;
}

int main()
{
    Node *node5 = new Node(18);
    Node *node4 = new Node(32, node5);
    Node *node3 = new Node(67, node4);
    Node *node2 = new Node(25, node3);
    Node *node1 = new Node(12, node2);
    Node *head = new Node(0, node1);
    node5->SetNextNode(node3); // 入口节点为node3, data=67

    Node *entry = nullptr;
    bool hasCircle = HasCircle(head, entry);
    if (hasCircle)
    {
        std::cout << "有环, 入口节点数据=" << entry->GetData() << std::endl;
    }
    else
    {
        std::cout << "没有环" << std::endl;
    }
}