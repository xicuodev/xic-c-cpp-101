#include <stdio.h>

void DD9 ();
void D9 ();

int main () {
    DD9(); // 使用二维阵列
    D9(); // 使用一维阵列
    return 0;
}

void DD9 () {
    /* int v[3][3] = { // 定义一个 3x3 的二维阵列
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; */
    // 更好的定义方法·使用 for 语句
    int v[3][3], i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            v[i][j] = i * 3 + (j + 1); // 推估表达式，也可使用递增变量 k 依序赋值
        }
    }

    for (i = 0; i < 3; i++) { // 横行
        for (j = 0; j < 3; j++) { // 纵列
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void D9 () {
    int v[9], i;
    for (i = 0; i < 9; i++) {
        v[i] = i + 1;
    }
    for (i = 0; i < 9; i++) {
        printf("%d ", v[i]);
        if (i % 3 == 2) { // 需求：i 为 2，5，8 时换行；要判断之，只需 i 除以 3 余 2
            printf("\n");
        }
    }
}