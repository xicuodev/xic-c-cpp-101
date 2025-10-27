#pragma once
#include <iostream>
#include <time.h>
#include "Array.hpp"

Array *getRandomTestArray(int size, int scope)
{
    Array *arr = new Array(size);
    srand((time(0))); // 用系统时间种下一颗随机数种子

    // 测试尾插接口
    for (int i = 0; i < size; i++)
    {
        arr->push_back(rand() % scope);
    }

    cout << *arr << endl;
    return arr;
}