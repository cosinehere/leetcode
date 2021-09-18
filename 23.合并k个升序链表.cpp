/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (55.91%)
 * Likes:    1510
 * Dislikes: 0
 * Total Accepted:    319.4K
 * Total Submissions: 571.3K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
 * 
 * 
 */

#include <vector>
#include <algorithm>
using std::vector;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = nullptr, *temp = nullptr;
        vector<ListNode*> cur;
        for (size_t i = 0; i < lists.size(); ++i) {
            if (lists[i] != nullptr) {
                cur.push_back(lists[i]);
            }
        }
        auto cmp = [](const ListNode *a, const ListNode *b) { return a->val > b->val; };
        std::make_heap(cur.begin(), cur.end(), cmp);

        for (; !cur.empty();) {
            if (ret == nullptr) {
                ret = cur.front();
                temp = ret;
            }
            else {
                temp->next = cur.front();
                temp = temp->next;
            }
            ListNode *next = cur.front()->next;
            std::pop_heap(cur.begin(), cur.end(), cmp);
            cur.pop_back();
            if (next != nullptr) {
                cur.push_back(next);
                std::push_heap(cur.begin(), cur.end(), cmp);
            }
        }

        return ret;
    }
};
// @lc code=end

