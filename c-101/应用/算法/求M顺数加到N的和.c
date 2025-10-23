#include <stdio.h>
int main()
{
    /* 从 M 正数加到 N */
    // 获取 M 和 N
    int M, N;
    printf("键入你想从 M 顺数加到 N 的 M：");
    scanf("%d", &M);
    printf("现在键入从 M 顺数加到 N 的 N：");
    scanf("%d", &N);
    /* 方法 1：使用 for 循环述句暴力求值
    int i;
    int sum = 0;
    for (i = M; i <= N; i++)
    {
        sum = sum + i;
    }*/
    // 方法 2：使用等差数列求和公式优雅求值
    int sum = (N + M) * (N - M + 1) / 2;
    printf("%d", sum);
    return 0;
}