/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] 区域和检索 - 数组可修改
 *
 * https://leetcode-cn.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (54.25%)
 * Likes:    293
 * Dislikes: 0
 * Total Accepted:    23.4K
 * Total Submissions: 43.2K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * 给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。
 * 
 * 实现 NumArray 类：
 * 
 * 
 * 
 * 
 * NumArray(int[] nums) 用整数数组 nums 初始化对象
 * void update(int index, int val) 将 nums[index] 的值更新为 val
 * int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] +
 * nums[left + 1], ..., nums[right]）
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["NumArray", "sumRange", "update", "sumRange"]
 * [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
 * 输出：
 * [null, 9, null, 8]
 * 
 * 解释：
 * NumArray numArray = new NumArray([1, 3, 5]);
 * numArray.sumRange(0, 2); // 返回 9 ，sum([1,3,5]) = 9
 * numArray.update(1, 2);   // nums = [1,2,5]
 * numArray.sumRange(0, 2); // 返回 8 ，sum([1,2,5]) = 8
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -100 
 * 0 
 * -100 
 * 0 
 * 最多调用 3 * 10^4 次 update 和 sumRange 方法
 * 
 * 
 * 
 * 
 */

#include <vector>
using std::vector;

// @lc code=start
class NumArray {
public:
    NumArray(vector<int>& nums) {
        size = nums.size();
        v.assign(size + 1, 0);
        v[0] = 0;
        for (size_t i = 1; i <= size; ++i) {
            v[i] += nums[i - 1];
            size_t j = i + lowbit(i);
            if (j <= size) {
                v[j] += v[i];
            }
        }
    }
    
    void update(int index, int val) {
        int sum = val - getsum(index + 1) + getsum(index);
        modify(index + 1, sum);
    }
    
    int sumRange(int left, int right) {
        return getsum(right + 1) - getsum(left);
    }

private:
    vector<int> v;
    int size;

    inline void modify(const int x, const int val) {
        for (int i = x; i <= size; i += lowbit(i)) {
            v[i] += val;
        }
    }

    inline const int getsum(const int x) {
        int ret = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            ret += v[i];
        }
        return ret;
    }

    inline const int lowbit(const int x) {
        return x & (-x);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

