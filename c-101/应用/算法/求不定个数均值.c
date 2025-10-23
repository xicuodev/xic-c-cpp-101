#include <stdio.h>
int main(){
    int num;
    int sum = 0;
    int count = 0;
    float avg;
    printf("键入要求均值的若干个数字（q 代表退出）：\n");
    scanf("%d", &num);
    while (num != 0)
    {
        sum = sum + num;
        count++;
        scanf("%d", &num);
    }
    avg = (float) sum / count;
    printf("均值为 %f。\n", avg);
    return 0;
}