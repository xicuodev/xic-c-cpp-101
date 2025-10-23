#include <stdio.h>

int main () {
    const int a = 1; // const 唯读
    const int b[3] = {2, 1, 3};
    // const int c; 未定义行为
    // a = 2; 编译失败
    // b[0] = 1; 编译失败
    // printf(const char *, ...);（字串字面常数的资料型别）
    char strA[] = "kinoko7";
    char *strB = "test"; // 不安全
    const char *strC = "const test"; // 安全，明确设定所指字元唯读
    // strB[0] = 'T'; 未定义行为，但编译通过
    // strC[0] = 'T'; 编译失败
    // strB = strC; (char *) = (const char *) 编译失败，尝试取消所指字元唯读
    strC = strB; // (型别 *) 可以转成 (const 型别 *)，效果为设定所指变数唯读
    return 0;
}