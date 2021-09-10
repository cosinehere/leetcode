/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (40.80%)
 * Likes:    1773
 * Dislikes: 0
 * Total Accepted:    610.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";

        size_t minlen = strs[0].length();
        for (size_t i = 1; i < strs.size(); ++i) {
            minlen = std::min(strs[i].length(), minlen);
        }

        for (size_t i = 0; i < minlen; ++i) {
            bool same = true;
            char ch = ' ';
            for (size_t j = 0; j < strs.size(); ++j) {
                if (ch == ' ') {
                    ch = strs[j][i];
                } else if (ch != strs[j][i]) {
                    same = false;
                    break;
                }
            }
            if (!same) {
                break;
            }
            else {
                ret += ch;
            }
        }

        return ret;
    }
};
// @lc code=end

