#include <stdio.h>
int main()
{
    int N;
    printf("键入你想用 * 绘制的 N * N 的实心矩形的 N：");
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    int M;
    printf("现在键入你想用 * 绘制的 M * M 的空心矩形的 M：");
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 || i == M - 1 || j == 0 || j == M - 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}