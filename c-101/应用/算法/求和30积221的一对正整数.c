#include <stdio.h>
int main()
{
    /* 求和为 30 积为 221 的一对正整数 */
    // 通过评估变量范围，抓住变量关系，来提高效率
    for (int i = 1; i <= 30 / 2; i++) // 由于 i, j 无序，故 i 只需跑一半
    {
        int j = 30 - i; // 由于 i 和 j 的和为 10，故 i 决定 j
        if (i * j == 221)
        {
            printf("The solution is (%d, %d).\n", i, j);
        }
    }
    return 0;
}