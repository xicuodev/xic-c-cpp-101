#include <stdio.h>
int main()
{
    int i, X;
    printf("键入你想寻找其所有正因数的正整数 X：");
    scanf("%d", &X);
    for (i = 1; i <= X; i++)
    {
        if (X % i == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}