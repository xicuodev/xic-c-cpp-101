#include <stdio.h>

void vPrint (int (*q)[3]) { // 问题：阵列的长度是钉死的
    // 1. 传入变数不能写成 int (*q)[] 吗？== int *(*q) == int **q
    // 2. 此时，sizeof(*q) 求的是一个指向整数的指标的记忆体占用，目标阵列长度信息已经丢失
    for (int i = 0; i < sizeof(*q)/sizeof((*q)[0]); i++) {
        printf("%d ", (*q)[i]);
    }
    printf("\n");
}

int main () {
    int v[3] = {2, 1, 3};
    vPrint(&v); // 3. (int **) = (int (*)[3]) 这样的转型能做到吗？
        // 绝大部分情况下，指向不同型别的指标间不能隐性转型
        // (int *) = (double *) 未定义行为
        // (int **) = (int (*)[3]) 未定义行为
        // (int **) = (int *) 未定义行为
    return 0;
}