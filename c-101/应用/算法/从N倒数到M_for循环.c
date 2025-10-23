#include <stdio.h>
int main()
{
    int i, M, N;
    printf("键入你想从 N 倒数到 M 的 N：");
    scanf("%d", &N);
    printf("现在键入从 N 倒数到 M 的 M：");
    scanf("%d", &M);
    for (i = N; i >= M; i--)
    {
        printf("%d\n", i);
    }
    return 0;
}