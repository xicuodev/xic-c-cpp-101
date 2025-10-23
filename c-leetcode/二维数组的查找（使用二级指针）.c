#include <stdio.h>
#include <stdbool.h>

bool findNumIn2DArray (int **matrix2d, int rows, int cols, int tar) { // 从右上始，遇小则下，逢大便左
    if (rows == 0 || cols == 0) return false; // 极端情况
    int x = cols - 1, y = 0;
    while (x >= 0 && y < rows) {
        if (matrix2d[y][x] < tar) y++; // == *(*(matrix2d + y) + x)
        else if (matrix2d[y][x] > tar) x--;
        else return true;
    }
    return false;
}

void output (bool input) {
    if (input == 1) {
        printf("true\n");
    } else if (input == 0) {
        printf("false\n");
    }
}

int main () {
    int m2d[5][5] = {
        {1,  2,  3,  4,  10},
        {2,  3,  4,  5,  11},
        {3,  4,  5,  6,  12},
        {10, 19, 22, 37, 98},
        {18, 21, 35, 46, 99}
    }; // 矩阵向右下角单调递增
    int *p[5] = {m2d[0], m2d[1], m2d[2], m2d[3], m2d[4]};
    int tarO = 5; // 将返回 true
    int tarX = 77; // 将返回 false
    output(findNumIn2DArray(p, 5, 5, tarO));
    output(findNumIn2DArray(p, 5, 5, tarX));
    return 0;
}