#include <stdio.h>

int main() { // 需求 & 实现：用户输入一组（5 个）整数，经泡沫法排序，输出
	int v[5], i, j;

	// 输入
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &v[i]);
	}

	// 泡沫排序·由小到大
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++) // 看
		{
			if (v[j] > v[j+1]) // 若左边大于右边，则交换二者
			{
				int t = v[j];
				v[j] = v[j + 1];
				v[j + 1] = t;
			}
		}
	}

	// 输出
	for (i = 0; i < 5; i++)
	{
		printf("%d, ", v[i]);
	}
}