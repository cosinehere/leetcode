/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (40.83%)
 * Likes:    6736
 * Dislikes: 0
 * Total Accepted:    983.5K
 * Total Submissions: 2.4M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 
 * 题目数据保证列表表示的数字不含前导零
 * 
 * 
 */

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        int c = 0;
        ListNode *h = nullptr;
        ListNode *cur = nullptr;
        while (p1 != nullptr || p2 != nullptr) {
            if (h == nullptr) {
                h = new ListNode();
                cur = h;
            } else {
                cur->next = new ListNode();
                cur = cur->next;
            }

            if (p1 == nullptr) {
                cur->val = p2->val + c;
                c = cur->val / 10;
                cur->val %= 10;
                p2 = p2->next;
            } else if (p2 == nullptr) {
                cur->val = p1->val + c;
                c = cur->val / 10;
                cur->val %= 10;
                p1 = p1->next;
            } else {
                cur->val = p1->val + p2->val + c;
                c = cur->val / 10;
                cur->val %= 10;

                p1 = p1->next;
                p2 = p2->next;
            }
        }

        if (c > 0) {
            cur->next = new ListNode(c);
        }
        return h;
    }
};
// @lc code=end

