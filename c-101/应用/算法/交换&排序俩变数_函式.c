#include <stdio.h>

void swap (int *, int *); // 交换
void sort (int *, int *); // 排序

int main () {
    int a = 2, b = 3;
    swap(&a, &b);
    printf("%d, %d\n", a, b);
    sort(&a, &b);
    printf("%d, %d\n", a, b);
    return 0;
}

void swap (int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sort (int *a, int *b) {
    if (*a > *b) {
        swap(a, b);
    }
}