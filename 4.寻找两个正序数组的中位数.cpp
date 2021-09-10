/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (40.79%)
 * Likes:    4464
 * Dislikes: 0
 * Total Accepted:    499.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums1 = [1,3], nums2 = [2]
 * 输出：2.00000
 * 解释：合并数组 = [1,2,3] ，中位数 2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums1 = [1,2], nums2 = [3,4]
 * 输出：2.50000
 * 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums1 = [0,0], nums2 = [0,0]
 * 输出：0.00000
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums1 = [], nums2 = [1]
 * 输出：1.00000
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：nums1 = [2], nums2 = []
 * 输出：2.00000
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 
 * 0 
 * 1 
 * -10^6 
 * 
 * 
 * 
 * 
 * 进阶：你能设计一个时间复杂度为 O(log (m+n)) 的算法解决此问题吗？
 * 
 */

#include <vector>
using std::vector;

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        int a = 0, b = 0;
        int pos = 0;
        while (a < nums1.size() || b < nums2.size()) {
            int num;
            if (a >= nums1.size()) {
                num = nums2[b];
                ++b;
            } else if (b >= nums2.size()) {
                num = nums1[a];
                ++a;
            } else if (nums1[a] < nums2[b]) {
                num = nums1[a];
                ++a;
            } else {
                num = nums2[b];
                ++b;
            }

            if (pos == (nums1.size() + nums2.size())/2) {
                ans += num;
            }
            if (!((nums1.size() + nums2.size())&1)) {
                if (pos + 1 == (nums1.size() + nums2.size())/2) {
                    ans += num;
                }
            }
            ++pos;
            
        }
        if (!((nums1.size() + nums2.size())&1)) {
            ans /= 2;
        }
        return ans;
    }
};
// @lc code=end

