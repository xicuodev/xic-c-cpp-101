#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SinglyLinkedList.hpp"
using namespace std;

int main()
{
    SinglyLinkedList list;
    srand(time(0));
    for (int i = 0; i < 10; i++)
    {
        list.InsertHead(rand() % 100);
    }
    list.SelfShow();

    list.InsertHead(321);
    list.InsertTail(321);
    list.SelfShow();

    list.RemoveAll(321);
    list.SelfShow();

    list.InsertTail(123);
    list.SelfShow();
    SinglyLinkedList::Node *resultNode = list.FindFirst(123);
    cout << resultNode->GetData() << endl;

    return 0;
}