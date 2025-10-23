#include <stdio.h>
int main()
{
    int N;
    int isPrime = 1;
    printf("键入你想判断是否为质数的整数 N：");
    scanf("%d", &N);
    for (int i = 2; i < N && isPrime; i++)
    {
        if (N % i == 0) isPrime = 0;
    }   
    if (isPrime) printf("Y\n");
    else printf("N\n");
    return 0;
}