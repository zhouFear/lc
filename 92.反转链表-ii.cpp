
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        while (m-- > 1)
        {
            head = head->next;
        }
        ListNode* pre = head;
        head = head->next;
        ListNode* next;
        for (size_t i = 0; i < n-m; ++i)
        {
            next = head->next;
            pre->next = next;
            head->next = next->next;
            next->next = head;
            head = head->next;
        }
        return temp->next;
    }
};
// @lc code=end

