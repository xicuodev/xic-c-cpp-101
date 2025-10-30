#pragma once
#include <iostream>

using std::cout;
using std::endl;

class SinglyLinkedList
{
public:
    class Node
    {
        friend class SinglyLinkedList;

    public:
        Node(int data = 0, Node *nextNode = nullptr)
            : data_(data), nextNode_(nextNode) {}
        int GetData() { return data_; }
        void SetData(int data) { data_ = data; }
        Node *GetNextNode() { return nextNode_; }
        void SetNextNode(Node *nextNode) { nextNode_ = nextNode; }

    private:
        int data_;
        Node *nextNode_;
    };

public:
    SinglyLinkedList()
    {
        headNode_ = new Node();
    }
    ~SinglyLinkedList()
    {
        // 释放所有节点
        Node *node = headNode_;
        while (node != nullptr)
        {
            headNode_ = headNode_->nextNode_;
            delete node;
            node = headNode_;
        }
    }

public:
    // 尾插, O(n) 如果维护了tailNode_那就是O(1)
    void InsertTail(int value)
    {
        // 找到末尾节点
        Node *tailNode = headNode_;
        while (tailNode->nextNode_ != nullptr)
        {
            tailNode = tailNode->nextNode_;
        }
        // 创建新节点
        Node *newNode = new Node(value);
        // 接上末尾节点
        tailNode->nextNode_ = newNode;
    }

    void InsertHead(int value)
    {
        Node *newNode = new Node(value);
        newNode->nextNode_ = headNode_->nextNode_;
        headNode_->nextNode_ = newNode;
    }

    void SelfShow()
    {
        Node *node = headNode_->nextNode_;
        while (node != nullptr)
        {
            cout << node->data_ << ' ';
            node = node->nextNode_;
        }
        cout << endl;
    }

    // 删除所有值为value的节点, O(n)
    void RemoveAll(int value)
    {
        Node *leader = headNode_->nextNode_;
        Node *follower = headNode_; // 跟班，负责记录前驱
        while (leader != nullptr)
        {
            if (leader->data_ == value)
            {
                follower->nextNode_ = leader->nextNode_;
                delete leader;
                // leader变成野指针了，故维护leader
                leader = follower->nextNode_;
                continue;
            }
            follower = leader; // 跟班先走
            leader = leader->nextNode_;
        }
    }

    // 查找第一个值为value的节点, O(n)
    Node *FindFirst(int value)
    {
        Node *node = headNode_->nextNode_;
        while (node != nullptr)
        {
            if (node->data_ == value)
            {
                return node;
            }
            node = node->nextNode_;
        }
        return nullptr;
    }

    Node *GetHeadNode()
    {
        return headNode_;
    }

private:
    // 头节点，一般不存数据，或者可以存元素个数，自由发挥
    Node *headNode_;
};
