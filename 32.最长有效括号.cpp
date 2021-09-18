/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (35.62%)
 * Likes:    1456
 * Dislikes: 0
 * Total Accepted:    187.6K
 * Total Submissions: 526K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */

#include <string>
#include <stack>
#include <vector>
using std::string;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> st;
        std::vector<bool> match;
        match.assign(s.size(), true);
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    match[i] = false;
                } else {
                    st.pop();
                }
            }
        }
        while (!st.empty()) {
            match[st.top()] = false;
            st.pop();
        }

        int ans = 0;
        int cnt = 0;
        for (size_t i = 0; i < match.size(); ++i) {
            if (match[i]) {
                ++cnt;
            } else {
                if (cnt > ans) ans = cnt;
                cnt = 0;
            }
        }
        if (cnt > ans) ans = cnt;
        return ans;
    }
};
// @lc code=end

