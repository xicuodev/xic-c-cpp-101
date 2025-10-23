#include <stdio.h>
int main()
{
    int side1, side2, side3, t;
    printf("逐次键入三角形的三整数边长：（例如：3 3 3）");
    scanf("%d%d%d", &side1, &side2, &side3);
    /* 按小中大排序 */
    if (side2 < side1)
    {
        t = side2; side2 = side1; side1 = t;
    }
    if (side3 < side1)
    {
        t = side3; side3 = side1; side1 = t;
    }
    if (side3 < side2)
    {
        t = side3; side3 = side2; side2 = t;
    }
    /*判断形状*/
    if (side1 == side3)
    {
        printf("是正三角形。\n");
    }
    if (side1 == side2 || side2 == side3)
    {
        printf("是等腰三角形。\n");
    }
    if (side1 * side1 + side2 * side2 == side3 * side3)
    {
        printf("是直角三角形。\n");
    }
    return 0;
}