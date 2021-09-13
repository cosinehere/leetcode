/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (80.09%)
 * Likes:    1319
 * Dislikes: 0
 * Total Accepted:    305.8K
 * Total Submissions: 381.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10 
 * nums 中的所有元素 互不相同
 * 
 * 
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        for (int i = 0; i < (1 << nums.size()); ++i) {
            int x = i;
            vector<int> grp;
            int cnt = 0;
            while (cnt < 10) {
                if (x & (1 << cnt))
                    grp.push_back(nums[cnt]);
                ++cnt;
            }
            ret.push_back(grp);
        }
        return ret;
    }
};
// @lc code=end

