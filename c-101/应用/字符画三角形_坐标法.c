#include <stdio.h>
int main()
{
    // 用坐标法绘制实心直角三角形
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
    printf("\n");

    // 用坐标法绘制空心直角三角形
    for (int y = 1; y <= 5; y++)
    {
        for (int x = 1; x <= 5; x++)
        {
            if (y == 5 || x == 1 || x == y)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}