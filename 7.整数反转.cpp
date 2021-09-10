/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int flag = (x & 0x80000000u) ? -1 : 1;
        unsigned int k = (flag == 1) ? x : (~x + 1u);
        int ret = 0;
        while (k) {
            if (ret <= ((0x1u << 31) - 1) / 10) {
                ret = ret * 10 + (k % 10);
            } else {
                return 0;
            }
            k /= 10;
        }

        return ret * flag;
    }
};
// @lc code=end

