#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Array.hpp"

using std::cout;
using std::endl;

int main()
{
    srand((time(0))); // 用系统时间种下一颗随机数种子
    Array arr;
    int size = 10;
    int scope = 100;

    // 测试尾插接口
    for (int i = 0; i < size; i++)
    {
        arr.PushBack(rand() % scope);
    }
    cout << arr << endl;

    // 测试尾删接口
    arr.PopBack();
    cout << arr << endl;

    // 测试插入接口
    arr.Insert(0, 123);
    cout << arr << endl;

    arr.Insert(arr.GetCurrentSize(), 321);
    cout << arr << endl;

    // 测试删除接口
    arr.RemoveAt(0);
    cout << arr << endl;

    // 测试查询接口
    int pos = arr.Find(321);
    if (pos != -1)
    {
        cout << "Value 321 found at: " << pos << endl;
    }
    else
    {
        cout << "Value 321 not found." << endl;
    }
}