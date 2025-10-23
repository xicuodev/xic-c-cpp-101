#include <stdio.h>
int main(){
    int a, b, c, min;
    printf("input: ");
    scanf("%d%d%d", &a, &b, &c);
    /* 假设修正法 */
    min = a;
    if (b < min){
        min = b;
    }
    if (c < min){
        min = c;
    }
    printf("min: %d\n", min);
    return 0;
}