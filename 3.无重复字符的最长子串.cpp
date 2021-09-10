/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 *
 * https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.96%)
 * Likes:    6090
 * Dislikes: 0
 * Total Accepted:    1.2M
 * Total Submissions: 3.2M
 * Testcase Example:  '"abcabcbb"'
 *
 * 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: s = "abcabcbb"
 * 输出: 3 
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 
 * 
 * 示例 3:
 * 
 * 
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 * 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 * 
 * 
 * 示例 4:
 * 
 * 
 * 输入: s = ""
 * 输出: 0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s 由英文字母、数字、符号和空格组成
 * 
 * 
 */

#include <string>
#include <set>
using std::string;
using std::set;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> ch;

        int ans = 0;
        int max = 0;
        for (size_t i = 0; i < s.length(); ++i) {
            if (ch.find(s[i]) == ch.end()) {
                max++;
                ch.insert(s[i]);
            } else {
                for (size_t j = 0; j < max; ++j) {
                    if (s[i - max + j] == s[i]) {
                        max -= j;
                        break;
                    } else {
                        ch.erase(s[i - max + j]);
                    }
                }
            }

            if (max > ans) {
                ans = max;
            }
        }
        return ans;
    }
};
// @lc code=end

