#include <stdio.h>

void vPrint (int **v, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", v[i][j]); // 传入 (int *) 的方案：v + i * width + j（推估表达式）
        }
        printf("\n");
    }
}

int main () {
    int v[2][3] = {{1, 2, 3}, {4, 5, 6}};
    // vPrint(v, 2, 3);
        // 问题：v（阵列）-> &v[0]（阵列的指标，指向 {1, 2, 3}）-/> (int **)（指标的指标，透过桥接指向元素 1）
        // 解决方案：使用指标阵列（存各子阵列的首项位址）
    int *p[2] = {v[0], v[1]}; // (int [3]) -> (int *)，例如 v[1] -> &v[1][0]
    vPrint(p, 2, 3); // (int *[2]) -> (int **)，p -> &p[0] == &v[0] -> &&v[0][0]
        // 传入 (int *) 方案：vPrint((int *)v, 2, 3);（强制转型）
    return 0;
}