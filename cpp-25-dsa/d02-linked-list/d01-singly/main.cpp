#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SinglyLinkedListMock.hpp"

using std::cout;
using std::endl;

typedef SinglyLinkedList::Node Node;

int main()
{
    SinglyLinkedList &list = GetMockRandomSinglyLinkedList();
    list.SelfShow();

    list.InsertHead(321);
    list.InsertTail(321);
    list.SelfShow();

    list.RemoveAll(321);
    list.SelfShow();

    list.InsertTail(123);
    list.SelfShow();
    Node *resultNode = list.FindFirst(123);
    cout << resultNode->GetData() << endl;
}