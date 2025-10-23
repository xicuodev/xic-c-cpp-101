#include <stdio.h>
int main()
{
    int M, N;
    printf("键入你想从 M 顺数到 N 的 M：");
    scanf("%d", &M);
    printf("现在键入从 M 顺数到 N 的 N：");
    scanf("%d", &N);
    while (M <= N)
    {
        printf("%d\n", M);
        M++;
    }
    return 0;
}