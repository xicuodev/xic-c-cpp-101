#include <stdio.h>
int main(){
    int num;
    int sum = 0;
    printf("键入要求和的若干个数字（0 代表退出）：\n");
    scanf("%d", &num);
    while (num != 0)
    {
        sum = sum + num;
        scanf("%d", &num);
    }
    printf("和为 %d。\n", sum);
    return 0;
}