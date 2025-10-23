#include <stdio.h>
#include <stdlib.h> // 提供 malloc、free 和 realloc 函式，动态配置记忆体，可解决变数生命周期过短的问题（见 thirdTry 和 main）

void firstTry () { // 首次尝试
    // int nums[?]; // 最后的问题：阵列的长度如何设定？怎样让阵列长度自适应使用者的输入？
    int len = 0;
    while (1) {
        int input;
        scanf("%d", &input); // 听取使用者输入整数
        if (input == 0) break; // 直到听到 0 终止
        // nums[len] = input; // 把听到的整数存到阵列中
        len++;
    }
}

void secondTry () { // 解决方案：使用指标，控制其指向更长的阵列
    int *nums;
    int len = 0;
    while (1) {
        int input;
        scanf("%d", &input);
        if (input == 0) break;
        int growNums[len + 1];
        for (int i = 0; i < len; i++) growNums[i] = nums[i]; // 复制 nums 所指的 旧 growNums 阵列 到 新 growNums 阵列
        nums = growNums; // 控制 nums 指向新 growNums 阵列开头
        nums[len] = input; // 把听到的整数存到 nums 所指的新 growNums 阵列结尾
        len++;
    } // 新的问题：这里此次回圈的 growNums 已经释放，复制的信息存不下来（变数的生命周期）
        // 此时执行下一次回圈，透过 nums 已经无法存取（追踪）原本的旧 growNums 阵列
}

void thirdTry () {
    int *nums = 0; // ($) 初始化 nums 为空指标 (NULL)
    int len = 0;
    while (1) {
        int input;
        scanf("%d", &input);
        if (input == 0) break;
        int *growNums = malloc(sizeof(int) * (len + 1)); // 透过 malloc 函式主动配置的记忆体空间不会自动释放（返回配置好的记忆体空间的开头位址）
        for (int i = 0; i < len; i++) growNums[i] = nums[i]; // 该行存在两次追踪：nums -> growNums -> (malloc 产生的阵列)
        free(nums); // (*) 释放旧 growNums 阵列（若传入指标为空指标，则跳过）
            // 问题 2：首次回圈并没有旧阵列可以归还，未定义行为
            // 解决方案：空指标（值为 0），见上文 ($)
        nums = growNums;
        nums[len] = input;
        len++;
    } // 此时，nums 和它指向的阵列都会保留下来
        // 问题 1：以往每次回圈产生的旧阵列一直没有归还（释放），一直只借不还会导致"记忆体泄漏" (Memory leak)
        // 解决方案：见上文 (*)
} // 问题 3：每次遇到此类需求都要写重新配置的代码，过于麻烦
// 解决方案：realloc 函式

int main () { // lastTry
    int *nums = 0;
    int len = 0;
    while (1) {
        int input;
        scanf("%d", &input);
        if (input == 0) break;
        nums = realloc(nums, sizeof(int) * (len + 1)); // 重新配置阵列和指向它的指标
            // 优化更好，有可能不需要搬家，会更有效率
        nums[len] = input;
        len++;
    }
    printf("输入的数字：");
    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}