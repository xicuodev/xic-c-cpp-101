#include <stdio.h>
int main()
{
    int customer;
    printf("键入顾客人数：");
    scanf("%d", &customer);
    int total = customer * 300;
    if (total >= 3000)
    {
        total = total * 0.8;
    }
    printf("应付：%d\n", total);
    return 0;
}