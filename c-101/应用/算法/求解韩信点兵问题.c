#include <stdio.h>
int main()
{
    // 印出正数第一个符合韩信点兵的数
    /* while 述句的写法
    int i = 0;
    while (!(i % 3 == 2 && i % 5 == 3 && i % 7 == 2))
    {
        i++;
    }*/
    // for 述句的写法
    int i;
    for (i = 0; !(i % 3 == 2 && i % 5 == 3 && i % 7 == 2); i++)
        ;
    printf("1. 正数第一个符合韩信点兵的数：%d\n", i);
    // 印出 M 正数到 N 中所有符合韩信点兵的数
    int M, N;
    printf("2. 键入你想印出 M 正数到 N 中所有符合韩信点兵的数的 M：");
    scanf("%d", &M);
    printf("现在键入你想要的 N：");
    scanf("%d", &N);
    for (i = M; i <= N; i++)
    {
        if (i % 3 == 2 && i % 5 == 3 && i % 7 == 2)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    // 印出从 X 开始倒数第一个符合韩信点兵的数
    int X;
    printf("3. 键入你想印出从 X 开始倒数第一个符合韩信点兵的数的 X：");
    scanf("%d", &X);
    for (i = X; i > 0 && !(i % 3 == 2 && i % 5 == 3 && i % 7 == 2); i--)
        ;
    if (i > 0)
    {
        printf("%d\n", i);
    }
    else if (i <= 0)
    {
        printf("在给定范围内未找到符合条件的数。\n");
    }
    // 印出 1 到 1000 中的第 Y 个韩信数
    int Y, count;
    printf("4. 键入你想印出 1 到 1000 中的第 Y 个韩信数的 Y：");
    scanf("%d", &Y);
    for (i = 1, count = 0; i <= 1000 && count < Y; i++)
    {
        if (i % 3 == 2 && i % 5 == 3 && i % 7 == 2)
        {
            count++;
        }
        if (count == Y)
        {
            printf("%d\n", i);
        }
        else if (i == 1000)
        {
            printf("未找到第 %d 个符合条件的数，因为该序数的最大值为 %d。", Y, count);
        }
    }
    return 0;
}