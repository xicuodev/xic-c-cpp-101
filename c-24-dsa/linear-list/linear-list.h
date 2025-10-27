#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// #define MAXSIZE 100
const int MaxSize = 100;

typedef int ElemType;
typedef struct {
    ElemType *data;
    int length;
} LinearList;

// 1. 初始化线性表
LinearList *init();
// 2. 释放线性表
void myFree(LinearList *);
// 3. 判断线性表是否为空
bool isEmpty(LinearList *);
// 4. 判断线性表是否已满
bool isFull(LinearList *);
// 5. 增：在第 i 个位置插入元素
bool insert(LinearList *, int, ElemType);
// 6. 删：删除第一个值为 e 的元素
bool delete(LinearList *, ElemType);
// 7. 删：删除第 i 个位置的元素
bool deleteAt(LinearList *, int);
// 8. 查：查找第一个值为 e 的元素的位置
int find(LinearList *, ElemType);
// 9. 改：修改第一个值为 old 的元素的值为 new
bool modify(LinearList *, ElemType old, ElemType new);
// 10. 打印线性表
void print(LinearList *);

LinearList *init()
{
    LinearList *ll = (LinearList *)malloc(sizeof(LinearList));
    ll->data = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
    ll->length = 0;
    // 初始化元素为 0
    for (int i = 0; i < MaxSize; i++) ll->data[i] = 0;
    return ll;
}

void myFree(LinearList *ll) {
    if (ll) {
        free(ll->data);
        free(ll);
        printf("线性表已释放。\n");
    }
    else printf("线性表未初始化，无法释放。\n");
}

bool isEmpty(LinearList *ll) {
    return ll->length == 0;
}

bool isFull(LinearList *ll) {
    return ll->length >= MaxSize;
}

bool insert(LinearList *ll, int i, ElemType e) {
    if (!ll || isFull(ll)) {
        printf("线性表未初始化或已满，无法插入元素。\n");
        return false;
    }
    if (i < 1 || i > ll->length + 1) {
        printf("插入的位置 %d 不合法。\n", i);
        return false;
    }
    for (int j = ll->length; j >= i; j--) {
        ll->data[j] = ll->data[j - 1]; // 将元素后移
    }
    ll->data[i - 1] = e; // 插入新元素
    ll->length++;
    printf("成功在位置 %d 插入元素 %d。\n", i, e);
    printf("当前线性表长度为 %d。\n", ll->length);
    return true;
}

bool delete(LinearList *ll, ElemType e) {
    if (!ll || isEmpty(ll)) {
        printf("线性表未初始化或为空，无法删除元素。\n");
        return false;
    }
    for (int i = 0; i < ll->length; i++){
        if (ll->data[i] == e) {
            for (; i < ll->length - 1; i++) {
                ll->data[i] = ll->data[i + 1]; // 将元素前移
            }
            ll->length--;
            printf("成功在位置 %d 删除元素 %d。\n", i + 1, e);
            printf("当前线性表长度为 %d。\n", ll->length);
            return true;
        }
    }
    printf("未找到值为 %d 的元素。\n", e);
    return false;
}

bool deleteAt(LinearList *ll, int i){
    if (!ll || isEmpty(ll)) {
        printf("线性表未初始化或为空，无法删除元素。\n");
        return false;
    }
    if (i < 1 || i > ll->length) {
        printf("删除的位置 %d 不合法。\n", i);
        return false;
    }
    for (int j = i - 1; j < ll->length - 1; j++) {
        ll->data[j] = ll->data[j + 1]; // 将元素前移
    }
    ll->length--;
    printf("成功在位置 %d 删除元素 %d。\n", i, ll->data[i - 1]);
    printf("当前线性表长度为 %d。\n", ll->length);
    return true;
}

int find(LinearList*ll, ElemType e) {
    if (!ll || isEmpty(ll)) {
        printf("线性表未初始化或为空，无法查找元素。\n");
        return -1; // 未找到元素
    }
    for (int i = 0; i< ll->length; i++) {
        if (ll->data[i] == e) {
            printf("元素 %d 在位置 %d 第一次找到。\n", e, i + 1);
            return i + 1; // 返回位置，从 1 开始计数
        }
    }
    printf("未找到值为 %d 的元素。\n", e);
    return -1; // 未找到元素
}

bool modify(LinearList *ll, ElemType old, ElemType new) {
    if (!ll || isEmpty(ll)) {
        printf("线性表未初始化或为空，无法修改元素。\n");
        return false;
    }
    for (int i = 0; i < ll->length; i++) {
        if (ll->data[i] == old) {
            ll->data[i] = new; // 修改元素
            printf("成功将位置 %d 的元素 %d 修改为 %d。\n", i + 1, old, new);
            return true;
        }
    }
    printf("未找到值为 %d 的元素，无法修改。\n", old);
    return false; // 未找到元素
}

void print(LinearList *ll) {
    if (!ll || isEmpty(ll)) {
        printf("线性表未初始化或为空，无法打印。\n");
        return;
    }
    printf("线性表的元素：");
    for (int i = 0; i < ll->length; i++) {
        printf("%d, ", ll->data[i]);
    }
    printf("\n");
    printf("线性表的长度：%d\n", ll->length);
}