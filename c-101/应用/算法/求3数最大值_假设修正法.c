#include <stdio.h>
int main(){
    int a, b, c, max;
    printf("input: ");
    scanf("%d%d%d", &a, &b, &c);
    /* 假设修正法 */
    max = a;
    if (b > max){
        max = b;
    }
    if (c > max){
        max = c;
    }
    printf("max: %d\n", max);
    return 0;
}