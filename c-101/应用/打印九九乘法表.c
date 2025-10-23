#include <stdio.h>
int main()
{
    int k;
    printf("现打印九九乘法表：\n");
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            k = (i + 1) * (j + 1);
            printf("%d * %d = %d\n", i + 1, j + 1, k);
        }
    }
    return 0;
}