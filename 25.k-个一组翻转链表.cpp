/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (57.96%)
 * Likes:    447
 * Dislikes: 0
 * Total Accepted:    50.3K
 * Total Submissions: 86.7K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 * 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || !head->next || k == 0 || k == 1)
            return head;
        ListNode* h = new ListNode(0);
        h->next = head;
        bool needBreak = false;
        ListNode* h1 = h, *p1 = head, *p2 = p1->next, *p3, *end = head;
        while (1)
        {
            for(int i = 0; i < k; ++i) {
                if (!end) {
                    needBreak = true;
                    break;
                }
                end = end->next;
            }
            if (needBreak)
                break;
            
            while (p3!=end)
            {
                p3 = p2->next;
                p2->next = h1->next;
                h1->next = p2;
                p1->next = p3;
                p2 = p3;
            }
            h1 = p1;
            p1 = end;
            if (p1)
                p2 = p1->next;
        }
        return h->next;
    }
};
// @lc code=end

