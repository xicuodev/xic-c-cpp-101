#pragma once
#include <iostream>

using std::cout;
using std::endl;

class Array
{
public:
    Array(int size = 10) : mCurrentSize(0), mCapacity(size)
    {
        mpArray = new int[mCapacity];
    }
    ~Array()
    {
        delete[] mpArray;
        mpArray = nullptr;
    }

public:
    // 末尾添加元素, O(1)
    void PushBack(int value)
    {
        if (mCurrentSize == mCapacity)
        {
            int expandFactor = 2;
            cout << "Run out of capacity, 扩容数组为原来的 "
                 << expandFactor << " 倍。" << endl;
            // 扩容数组，常为2倍或1.5倍
            Expand(expandFactor * mCapacity);
        }
        mpArray[mCurrentSize++] = value;
    }
    // 末尾删除元素, O(1)
    void PopBack()
    {
        if (mCurrentSize == 0)
        {
            return;
        }
        // 不需要释放末尾元素内存，逻辑上删除
        mCurrentSize--;
    }
    // 按位置增加元素, O(n)
    // 本文件用到的position都表示index
    void Insert(int position, int value)
    {
        if (position < 0 || position > mCurrentSize)
        {
            throw "Invalid inerst position: " + std::to_string(position);
        }
        // 从末尾开始往后挪, O(n)
        for (int i = mCurrentSize - 1; i >= position; i--)
        {
            mpArray[i + 1] = mpArray[i];
        }
        mpArray[position] = value;
        mCurrentSize++;
    }
    // 按位置删除, O(n)
    void RemoveAt(int position)
    {
        if (position < 0 || position >= mCurrentSize)
        {
            throw "Invalid erase position: " + std::to_string(position);
        }
        // 从删除的后继位置开始往前挪, O(n)
        for (int i = position + 1; i < mCurrentSize; i++)
        {
            mpArray[i - 1] = mpArray[i];
        }
        mCurrentSize--;
    }
    // 查询元素位置, O(n)
    int Find(int value)
    {
        for (int i = 0; i < mCurrentSize; i++)
        {
            if (mpArray[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    // mCurrentSize的Getter
    int GetCurrentSize()
    {
        return mCurrentSize;
    }
    // 重载索引访问运算符
    int operator[](int index)
    {
        return mpArray[index];
    }

private:
    // 内部数组扩容接口, O(n)
    void Expand(int size)
    {
        // 开辟更长的内存
        int *mpLongerArray = new int[size];
        // 复制原内存到新内存, O(n)
        memcpy(mpLongerArray, mpArray, sizeof(int) * mCapacity);
        // 释放原内存
        delete[] mpArray;
        // 更新数组指针
        mpArray = mpLongerArray;
        // 更新数组容量
        mCapacity = size;
    }

    int *mpArray;     // 指向可扩容的数组内存
    int mCapacity;    // 数组的容量
    int mCurrentSize; // 数组有效元素个数
};

// 打印数组元素
std::ostream &operator<<(std::ostream &cout, Array &array)
{
    cout << '[';
    for (int i = 0; i < array.GetCurrentSize() - 1; i++)
    {
        cout << array[i] << ',';
    }
    return cout << array[array.GetCurrentSize() - 1] << ']';
}