// 从这份文件开始使用大陆术语（李老师的公开基础课程刷完了 T_T）
#include <stdio.h>

void merge (int *nums1, int len_nums1, int *nums2, int len_nums2) {
    int i = len_nums1 - 1, j = len_nums2 - 1; // 引入两个数组的末项序号
    for (int k = len_nums1 + len_nums2 - 1; k >= 0; k--) { // 从合并数组结尾开始，反向递增
        if (i < 0) {
            nums1[k] = nums2[j--];
        }
        else if (j < 0) {
            nums1[k] = nums1[i--];
        }
        else {
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j--;
            }
            else {
                nums1[k] = nums1[i];
                i--;
            }
        }
    }
}

int main () {
    int nums1[] = {2, 3, 6, 8, 9, 0, 0, 0};
    int len1 = 5;
    int nums2[] = {1, 2, 4};
    int len2 = 3;
    int nums3[] = {0};
    int len3 = 0;
    int nums4[] = {};
    int len4 = 0;
    merge(nums1, len1, nums2, len2);
    for (int i = 0; i < len1 + len2; i++) {
        printf("%d ", nums1[i]);
    }
    printf("\n");
    return 0;
}