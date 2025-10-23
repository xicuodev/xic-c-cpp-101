#include <stdio.h>

int main () {
    int v[5] = {9, 2, 6, 1, 3};
    int *n = v; // 等价于 int *n = &v[0];
    for (int i = 0; i < 5; i++) {
        printf("%d, ", *(n+i)); // *(n+i) == *(&v[0] + i) == *&v[i] == v[i]
    }
    printf("\n");
    // 全部使用指标的方案
    int *m;
    for (m = v; m != &v[5]; m++) {
        printf("%d, ", *m);
    }
    printf("\n");
    // 使用 while 述句的方案
    int *k = v;
    while (k != v + 5) {
        printf("%d, ", *k);
        k++;
    }
    printf("\n");
    return 0;
}