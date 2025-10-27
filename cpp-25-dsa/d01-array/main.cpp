#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Array.hpp"
#include "ArrayTest.hpp"
using namespace std;

int main()
{
    Array &arr = *getRandomTestArray(10, 100);

    // 测试尾删接口
    arr.pop_back();
    cout << arr << endl;

    // 测试插入接口
    arr.insert(0, 123);
    cout << arr << endl;

    arr.insert(arr.getCurrentSize(), 321);
    cout << arr << endl;

    // 测试删除接口
    arr.erase(0);
    cout << arr << endl;

    // 测试查询接口
    int pos = arr.find(321);
    if (pos != -1)
    {
        cout << "Value 321 found at: " << pos << endl;
    }
    else
    {
        cout << "Value 321 not found." << endl;
    }

    return 0;
}