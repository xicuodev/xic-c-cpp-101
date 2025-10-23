#include <stdio.h>
int main(){
    // sizeof 函式的回传值为 size_t 型别（无号整数，printf 中用 %zu 指代）
    // 回传资料型别的位元占用
    printf("long int bytes: %zu\n", sizeof(long int));
    printf("int bytes: %zu\n", sizeof(int));

    // 回传数值的位元占用
    printf("size of 92613: %zu\n", sizeof(92613));

    // 用 sizeof 运算子求阵列元素个数（长度）
    int v[3];
    int vN = sizeof(v) / sizeof(v[0]);
    printf("v[3] 阵列的元素个数（长度）：%zu\n", vN);
    return 0;
}