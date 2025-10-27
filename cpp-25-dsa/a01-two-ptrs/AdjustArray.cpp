#include <iostream>
#include <time.h>

using std::cout;
using std::endl;

// 整型数组，把偶数调整到数组的左边，把奇数调整到数组的右边
void AdjustArray(int *arr, int size)
{
    int *p = arr;
    int *q = arr + size - 1;
    // O(n)
    while (p < q)
    {
        // p找奇数
        while (p < q)
        {
            if ((*p & 0b1) == 1)
            {
                break;
            }
            p++;
        }

        // q找偶数
        while (p < q)
        {
            if ((*q & 0b1) == 0)
            {
                break;
            }
            q--;
        }

        // p和q相遇代表结束
        if (p < q)
        {
            // p指奇数，q指偶数，交换
            int tmp = *p;
            *p = *q;
            *q = tmp;

            // 继续
            p++;
            q--;
        }
    }
}

int main()
{
    int *arr = new int[10];
    srand((time(0)));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;

    AdjustArray(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}
