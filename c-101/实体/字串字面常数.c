#include <stdio.h>

int main () {
    char strA[] = "A_Pi";
        // == {'A', '_', 'P', 'i', '\0'}，"\0"是字串结尾标识符
    char *strB = "A_Pi";
        // 字串字面常数，存在专门分配的位址，只读不写，可隐性转型成字元指标
    strA[0] = 'B'; // 可以直接修改某一个字元
    // strB[0] = 'C'; 编译失败，尝试写入一处唯读位址
    while (*strB != '\0') {
        printf("%c", *strB++);
    }
    printf("\n");
    return 0;
}