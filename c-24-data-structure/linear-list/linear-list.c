#include "linear-list.h"

int main() {
    LinearList* ll = init();
    ElemType e[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        insert(ll, i + 1, e[i]);
    }
    delete(ll, 20); // 尝试删除不存在的元素
    deleteAt(ll, 5); // 删除第 5 个位置的元素
    modify(ll, 6, 60); // 修改第一个值为 6 的元素为 60
    print(ll); // 打印线性表
    find(ll, 60); // 查找值为 60 的元素的位置
    find(ll, 100); // 查找不存在的元素
    insert(ll, 3, 30); // 在第 3 个位置插入元素 30
    print(ll); // 再次打印线性表
    delete(ll, 1);
    delete(ll, 3);
    myFree(ll); // 释放线性表
    printf("线性表操作完成。\n");
    return 0;
}