#include <stdio.h>

int main () {
    int v[3] = {2, 1, 3};
    printf("%d\n", v[2/3]); // 能跑，相当于 v[1]（整数型除法）
    // v[0.5] 编译错误
    // v[3/2.] 结果为 float，编译错误
    printf("阵列外的元素：%d\n", v[3]); // 未定义行为
    // v[4], v[-1] 未定义行为
    return 0;
}