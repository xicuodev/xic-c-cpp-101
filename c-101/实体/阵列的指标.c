#include <stdio.h>

int main () {
    int v[3] = {2, 1, 3};
    int (*q)[3] = &v; // int (*q)[3] 代表指标 q 指向了一个 3 元素的整型阵列
    for (int i = 0; i < 3; i++) {
        (*q)[i] = 0; // (*q) == v[3]
        printf("%d ", (*q)[i]);
    }
    printf("\n");
    return 0;
}