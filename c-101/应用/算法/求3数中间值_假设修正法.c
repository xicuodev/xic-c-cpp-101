#include <stdio.h>
int main()
{
    int a, b, c, mid;
    printf("input: ");
    scanf("%d%d%d", &a, &b, &c);
    /* 假设修正法 */
    mid = a;
    if (a <= b && b <= c || c <= b && b <= a)
    {
        mid = b;
    }
    if (a <= c && c <= b || b <= c && c <= a)
    {
        mid = c;
    }
    printf("min: %d\n", mid);
    return 0;
}