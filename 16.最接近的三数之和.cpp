/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.95%)
 * Likes:    877
 * Dislikes: 0
 * Total Accepted:    255.4K
 * Total Submissions: 555.8K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：nums = [-1,2,1,-4], target = 1
 * 输出：2
 * 解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 3 <= nums.length <= 10^3
 * -10^3 <= nums[i] <= 10^3
 * -10^4 <= target <= 10^4
 * 
 * 
 */

#include <cmath>
#include <vector>
#include <algorithm>
using std::vector;

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int diff = 0x7fffffff;
        int ret = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    ret = sum;
                }

                if (sum > target) {
                    --k;
                } else if (sum < target){
                    ++j;
                } else {
                    return target;
                }
            }
        }

        return ret;
    }
};
// @lc code=end

