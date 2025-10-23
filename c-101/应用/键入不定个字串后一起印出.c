#include <stdio.h>
#include <string.h>

void eg1 () { // 储存多个字串
    char strA[3][4] = {"How", "are", "you"}; // 二维阵列，方便修改字元，但容易造成浪费
    const char *strB[3] = {"How", "are", "you"}; // 指标阵列，不能修改字元，但可直接修改字串
    strA[2][0] = 'Y';
    strB[0] = "What";
    // 如何解决字串字面常数不能更改的问题？不用它
    char strC[5] = "What";
    strB[0] = strC; // 控制 strB[i] 指向一个可写的字串变数
    strC[0] = 'w';
    // 问题：每次都要新建一个变数吗？原来的字串字面常数不会浪费掉吗？
    // 解决方案：使用指标阵列，见 main 函式
}

int main () { // 输入不定个字串后一起印出
    char raw[5000];
    char *str[100]; // 记录每个输入字串的首项位址
    char input[50];
    int size = 0; // 输入字元个数
    int len = 0; // 输入字串个数
    while (1) {
        scanf("%s", input);
        if (strcmp(input, "END") == 0) break;
        str[len] = &raw[size];
        strcpy(str[len], input);
        size += strlen(input) + 1;
        len++;
    }
    for (int i = 0; i < len; i++) {
        printf("%s ", str[i]);
    }
    printf("\n(len: %d; size: %d)\n", len, size);
    return 0;
}