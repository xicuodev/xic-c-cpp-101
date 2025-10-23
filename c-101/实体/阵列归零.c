#include <stdio.h>

int main () {
    int v[5];
    int *p;
    for (p = v; p != &v[5]; p++) { // &v[5] == v+5，这个位址确实存在，但是已经不属于 v 阵列了
        *p = 0;
    }
    // 使用 while 述句的写法
    while (p != v + 5)
    {
        *p++ = 0; // 递增的特性，相当于 *p = 0; p++;
    }
    return 0;
}