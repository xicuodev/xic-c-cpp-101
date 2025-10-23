#include <stdio.h>

int main() {
    int n = 31629;
    int r = 0;
    while (n != 0) {
        int d = n % 10; // 每次循环：个位、十位……最高位
        printf("%d ", d);
        n /= 10; // 每次循环 n 去掉个位
    }
}