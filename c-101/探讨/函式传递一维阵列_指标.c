#include <stdio.h>

void vPrint (int *v, int N) { // 循序打印传入阵列元素
    for (int i = 0; i < N; i++) {
        printf("%d ", *(v+i));
    }
}

int main () {
    int u[3] = {2, 1, 3};
    int v[5] = {9, 2, 6, 1, 3};
    vPrint(u, 3); // 隐性转型：u -> &u[0]
    vPrint(v, 5); // 隐性转型：v -> &v[0]
    return 0;
}