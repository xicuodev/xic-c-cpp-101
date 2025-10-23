#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void DD9rand ();
void D9rand ();

int main () { // 实现：随机交换正序九宫格中的数字（交换法产生随机阵列）
    srand(time(0));
    DD9rand(); // 使用二维阵列
    D9rand(); // 使用一维阵列
    return 0;
} 

void DD9rand () {
    int v[3][3] = {{1, 2, 3}, {4, 5, 6},{7, 8, 9}};
    int i, j, k = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int r = rand() % (9 - k) + k; // 每次循环，r 的取值范围为 k~8（泡沫）
            // 回推坐标
            int m = r / 3;
            int n = r % 3;
            // 交换
            int t = v[i][j];
            v[i][j] = v[m][n];
            v[m][n] = t;
            k++;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
}

void D9rand () {
    int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    for (i = 0; i < 9; i++) {
        int m = rand() % (9 - i) + i; // 每次循环，m 的取值范围为 i~8（泡沫）
        int k = v[i];
        v[i] = v[m];
        v[m] = k;
    }
    for (i = 0; i < 9; i++) {
        printf("%d ", v[i]);
        if (i % 3 == 2) { // i 为 2，5，8 时换行
            printf("\n");
        }
    }
}