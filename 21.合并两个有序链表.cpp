/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (66.72%)
 * Likes:    1901
 * Dislikes: 0
 * Total Accepted:    693.3K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        ListNode *head = (l1->val < l2->val) ? l1 : l2;
        ListNode *ret = nullptr;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                if (ret == nullptr) {
                    ret = p1;
                    p1 = p1->next;
                } else {
                    ret->next = p1;
                    ret = p1;
                    p1 = p1->next;
                }
            } else {
                if (ret == nullptr) {
                    ret = p2;
                    p2 = p2->next;
                } else {
                    ret->next = p2;
                    ret = p2;
                    p2 = p2->next;
                }
            }
        }

        if (p1 == nullptr) {
            ret->next = p2;
        }
            
        if (p2 == nullptr) {
            ret->next = p1;
        }

        return head;
    }
};
// @lc code=end

