class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        
        // Dummy node simplifies edge case where left = 1
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        // Move prev to the node just before the reversal section
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // 'cur' is the first node in the reversal section
        // 'tail' will become the last node in the reversed section
        ListNode* cur = prev->next;
        ListNode* tail = cur;
        
        // Reverse the sublist [left, right]
        for (int i = 0; i < right - left; ++i) {
            ListNode* cache = cur->next;
            cur->next = cache->next;
            cache->next = prev->next;
            prev->next = cache;
        }
        
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};   
