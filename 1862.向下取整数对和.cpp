/*
 * @lc app=leetcode.cn id=1862 lang=cpp
 *
 * [1862] 向下取整数对和
 *
 * https://leetcode-cn.com/problems/sum-of-floored-pairs/description/
 *
 * algorithms
 * Hard (30.99%)
 * Likes:    22
 * Dislikes: 0
 * Total Accepted:    2.3K
 * Total Submissions: 7.2K
 * Testcase Example:  '[2,5,9]'
 *
 * 给你一个整数数组 nums ，请你返回所有下标对 0 <= i, j < nums.length 的 floor(nums[i] / nums[j])
 * 结果之和。由于答案可能会很大，请你返回答案对10^9 + 7 取余 的结果。
 * 
 * 函数 floor() 返回输入数字的整数部分。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：nums = [2,5,9]
 * 输出：10
 * 解释：
 * floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
 * floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
 * floor(5 / 2) = 2
 * floor(9 / 2) = 4
 * floor(9 / 5) = 1
 * 我们计算每一个数对商向下取整的结果并求和得到 10 。
 * 
 * 
 * 示例 2：
 * 
 * 输入：nums = [7,7,7,7,7,7,7]
 * 输出：49
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 
 * 
 */

#include <vector>
#include <cstring>
using std::vector;

// @lc code=start
class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        memset(prime, 0, sizeof(prime));
        for (int i = 2; i < MAXP; ++i) {
            if (!prime[i]) {
                for (int sum = i << 1; sum < MAXP; sum += i) {
                    prime[sum] = 1;
                }
            }
        }

        memset(primecnt, 0, sizeof(primecnt));
        for (int i = 0; i < nums.size(); ++i) {
            int tmp = nums[i];
            int j = 2;
            while(tmp) {
                while(prime[j]) { ++j; }
                while(tmp % j == 0) {
                    tmp /= j;
                    ++primecnt[j];
                }
            }
        }

        int ans = 0;
        constexpr int modulo = 1000000007;
        for (int i = 2; i < MAXP; ++i) {
            for (int j = 2; j < MAXP; ++j) {
                ans = (ans + i / j * primecnt[i]) % modulo;
            }
        }

        return ans;
    }

private:
    static constexpr int MAXP = 320;
    bool prime[MAXP];
    int primecnt[MAXP];
};
// @lc code=end

