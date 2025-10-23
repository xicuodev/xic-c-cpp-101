#include <stdio.h>

void selfAdd (int *nAddr) { // 使传入地址的变数的值递增 1
    *nAddr = *nAddr + 1; // * 间接运算子，透过位址找到对应变数
    // *nAddr++; 无法使 n 递增，相当于 *nAddr; nAddr++;
}

int main () {
    int n = 9;
    selfAdd(&n); // & 取址运算子
    printf("%d", n);
    return 0;
}