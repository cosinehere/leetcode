/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (33.41%)
 * Likes:    3748
 * Dislikes: 0
 * Total Accepted:    641.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0
 * 且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^5 
 * 
 * 
 */

#include <vector>
#include <map>
#include <set>
#include <algorithm>
using std::vector;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::map<int, int> bulk;
        for (size_t i = 0; i < nums.size(); ++i) {
            auto it = bulk.find(nums[i]);
            if (it == bulk.end()) {
                bulk.insert(std::pair<int, int>(nums[i], 1));
            } else {
                ++bulk[nums[i]];
            }
        }

        std::set<vector<int>> s;
        for (auto it = bulk.begin(); it != bulk.end(); ++it) {
            auto it2 = it;
            if (it->second < 2) {
                ++it2;
            }
            for (; it2 != bulk.end(); ++it2) {
                auto itf = bulk.find(0 - it->first - it2->first);
                if (itf != bulk.end() && itf->second > 0 &&
                    ((itf->first != it->first && itf->first != it2->first && it->first != it2->first)
                     || ((itf->first == it->first || itf->first == it2->first)
                         && it->first != it2->first && itf->second > 1)
                     || itf->second > 2)) {
                    vector<int> trip = {it->first, it2->first, itf->first};
                    std::sort(trip.begin(), trip.end());
                    s.insert(trip);
                }
            }
        }

        vector<vector<int>> ret;
        for (auto it = s.begin(); it != s.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
        

        /*
        std::sort(nums.begin(), nums.end());
        std::set<vector<int>> s;
        for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
            for (int j = i + 1; j < nums.size() && nums[j] + nums[i] <= 0; ++j) {
                int l = 0 - nums[i] - nums[j];
                for (int k = j + 1; k < nums.size() && nums[k] <= l; ++k) {
                    if (nums[k] == l) {
                        vector<int> tri = {nums[i], nums[j], l};
                        s.insert(tri);
                        break;
                    }
                }
            }
        }
        vector<vector<int>> ret;
        for (auto it = s.begin(); it != s.end(); ++it) {
            ret.push_back(*it);
        }
        return ret;
        */
    }
};
// @lc code=end

