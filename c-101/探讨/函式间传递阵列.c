#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 函式宣告，只需指定输入变量类型和顺序，无需指定输入变量名
void arrayRand (int[10]);
void arrayPrint (int[10]);
int arrayMax (int[10]);

int main () {
    srand(time(0));
    int v[10];
    arrayRand(v);
    printf("当前阵列：");
    arrayPrint(v); // * 此时，v 阵列并不会复制一份传到 arrayPrint 函式，而是链接到该函式
    printf("阵列最大项：%d\n", arrayMax(v));
}

void arrayRand (int v[10]) {
    for (int i = 0; i < 10; i++) {
        v[i] = rand() % 100; // 取值范围：0~99
    }
}

void arrayPrint (int v[10]) { // 打印输入阵列，直接对原阵列进行操作
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int arrayMax(int v[10]) { // 回传输入阵列最大项，直接对原阵列进行操作
    int max = v[0];
    for (int i = 1; i < 10; i++) { // 此时已假设 max 是 v[0]，故 i 从 1 开始
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}