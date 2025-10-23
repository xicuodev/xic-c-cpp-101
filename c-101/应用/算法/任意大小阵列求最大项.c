#include <stdio.h>

int max3 (int[3]); // 对 3 个元素的阵列求最大项（求任意阵列前 3 项最大项）
int maxv (int[], int N); // 对 N 个元素的阵列求最大项

int main () {
    int a[3] = {2, 1, 3};
    printf("3 元素阵列最大项：%d\n", max3(a));
    int b[5] = {9, 2, 6, 1, 3};
    printf("N 元素阵列最大项：%d\n", maxv(b, 5));
    return 0;
}

int max3 (int v[3]) { // * 这里 3 写与不写是一样的，v[3] 等效于 v[]（阵列作函式参数时，其大小并不重要）
    int max = v[0];
    for (int i = 1; i < 3; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}

int maxv (int v[], int N) { // ？函式参数 v[] 到底是什么（指标）
    int max = v[0];
    for (int i = 1; i < N; i++) { // ？一定要传入 N 吗
        if (v[i] > max) {
            max = v[i]; // ？如果 i 的值超过阵列范围会怎么样
        }
    }
    return max;
}