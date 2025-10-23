#include <stdio.h>
int main()
{
    int ans = 92;
    int guess;
    int count = 0;
    // 方法 1：使用 do while 述句
    do
    {
        printf("键入你猜测的数字：");
        scanf("%d", &guess);
        count++; // 计数
        /* 判断猜测数字与谜底数字的大小差别 */
        if (guess > ans)
        {
            printf("太大！\n");
        }
        else if (guess < ans)
        {
            printf("太小！\n");
        }
    } while (guess != ans);
    /* 方法 2：使用 while 述句
    while (count == 0 || guess != ans)
    {
        // 内部程式片段同方法 1
    }*/
    printf("猜得分毫不差！(%d 次)", count);
    return 0;
}