#pragma once
#include "SinglyLinkedList.hpp"
#include <time.h>

SinglyLinkedList &GetMockRandomSinglyLinkedList(int size = 10, int scope = 100)
{
    SinglyLinkedList *list = new SinglyLinkedList();
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        list->InsertHead(rand() % scope);
    }
    return *list;
}

SinglyLinkedList &GetMockOrderedSinglyLinkedList(int size = 10, int offset = 0)
{
    SinglyLinkedList *list = new SinglyLinkedList();
    for (int i = size - 1; i >= 0; i--)
    {
        list->InsertHead(i + offset);
    }
    return *list;
}
