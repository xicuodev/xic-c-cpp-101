#include <stdio.h>
int main(){
    int a, b, c, t;
    printf("键入你想要排序的三个数字；");
    scanf("%d%d%d", &a, &b, &c);
    printf("Before: %d %d %d\n", a, b, c);
    /* 一些处理，使按小中大排序 */
    if (b < a)
    {
        t = b; b = a; a = t;
    }
    if (c < a)
    {
        t = c; c = a; a = t;
    }
    if (c < b)
    {
        t = c; c = b; b = t;
    }
    printf("After: %d %d %d\n", a, b, c);
    return 0;
}