/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (47.22%)
 * Likes:    260
 * Dislikes: 0
 * Total Accepted:    42.9K
 * Total Submissions: 90.6K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* h = new ListNode(0);
        h->next = head;
        ListNode* p1 = head, *p2 = p1->next, *p3 = h;
        while (p2)
        {
            if (p2->val != p1->val)
            {
                if (p2 != p1->next)
                {
                    p3->next = p2;
                    p1 = p2;
                } else {
                    p3 = p3->next;
                    p1 = p2;
                }
            } else if (!p2->next) {
                if (p1->val == p2->val && p1 != p2)
                {
                    p3->next = nullptr;
                }
            }
            p2 = p2->next;
        }
        
        return h->next;
        
    }
};
// @lc code=end

