/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (35.34%)
 * Likes:    4066
 * Dislikes: 0
 * Total Accepted:    718.1K
 * Total Submissions: 2M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

#include <string>
using std::string;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 1;
        string ret = s.substr(0, 1);
        for (int i = 0; i < s.length(); ++i) {
            for (int l = ans + 1; i + l - 1 < s.length(); ++l) {
                bool fmt = true;
                for (int a = i, b = i + l - 1; a <= b; ++a, --b) {
                    if (s[a] != s[b]) {
                        fmt = false;
                        break;
                    }
                }
                if (fmt && l > ans) {
                    ans = l;
                    ret = s.substr(i, l);
                }
            }
        }
        return ret;
    }
};
// @lc code=end

