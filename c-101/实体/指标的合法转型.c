#include <stdio.h>

int main () {
    int intV = 3;
    char charV = '3';
    float floatV = 3.5f;
    double doubleV = 3.5;
    // 1. 同类型别内互转
    floatV = doubleV;
    intV = charV;

    // 2. 整数与浮点数互转
    intV = doubleV; // 浮点后无条件舍去
    doubleV = intV;
    printf("%d\n", intV);

    int v[3];
    int *n;
    const int *p;
    // 3. 阵列 转 指向阵列首项的指标
    n = v; // (int *) = (int [3])
    // v = n; (int [3]) = (int *) 未定义行为，指标转阵列

    // 4. (型别 *) 转 (const 型别 *)
    p = n; // (const int *) = (int *)
    // n = p; 未定义行为

    // 5. (void *) 转 部分型别的指标（其他大部分都是未定义行为）
    void *voidP = &intV; // 定义一个指向整型的空型指标（泛用的记忆体位址）
    double *doubleP = voidP; // 空型指标转浮点型指标，实作定义
    printf("%f\n", *doubleP);

    // 6. 指标与整数互转（需要强制转型，若整数存得下为实作定义，否则为未定义行为）
    int var = 7;
    int *ptr = &var;
    // int ptrInt = (int) ptr; // 手动强制转型
    // int *ptr2 = (int *) ptrInt;
    // int *ptr3 = (int *) 92613; // 应用于底层的硬体操作，有些记忆体位址会被绑定做某些功能
    // *ptr3 = 213;
    // printf("%d\n", *ptr3);

    // 7. 指标与指标互转（不一定可以，且需要强制转型）
        // 二者型别的记忆体存取位址的对齐若存在覆盖，则宽对齐的指标可转换为窄对齐的指标，也可以再转回来
    return 0;
}