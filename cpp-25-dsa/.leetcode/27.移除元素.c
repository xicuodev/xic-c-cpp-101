/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start
int removeElement(int *nums, int numsSize, int val)
{
    int *p = nums;
    int *q = nums + numsSize - 1;
    // p和q相遇时，它们所指的元素也要判断
    // 由于无法预料到p和q谁先和对方相遇，因此p和q的循环判断都需要覆盖到和对方相遇的情况
    // 如果q和对方相遇，所指元素为val，q离开p，外层循环结束；所指元素不为val，q停下，p继续判断
    // 如果p和对方相遇，所指元素为val，p停下，q继续判断；所指元素不为val，p离开q，外层循环结束
    // 所以无论何种情况，最终p总是会指向第一个无效元素，这是符合预期的
    while (p <= q)
    {
        // q找不等于val的元素
        while (p <= q)
        {
            if (*q != val)
            {
                break;
            }
            q--;
        }

        // p找等于val的元素
        while (p <= q)
        {
            if (*p == val)
            {
                break;
            }
            p++;
        }

        // p和q相遇代表结束
        if (p < q)
        {
            // q的元素直接覆盖p
            *p = *q;

            // 继续
            p++;
            q--;
        }
    }
    return p - nums;
}
// @lc code=end
