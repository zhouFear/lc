/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (68.49%)
 * Likes:    919
 * Dislikes: 0
 * Total Accepted:    220.7K
 * Total Submissions: 321.5K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 反转一个单链表。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 * 
 * 进阶:
 * 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }
        
        ListNode* temp = new ListNode(0);
        ListNode* p1 = head, *p2 = head->next;
        temp->next = head;
        while (p2)
        {
            p1 = p2->next;
            p2->next = temp->next;
            head->next = p1;
            temp->next = p2;
            p2 = p1;
        }
        return temp->next;
    }
};
// @lc code=end

