// 9 ms, 09/16/2017
// Time  : O(n)
// Space : O(1)
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head)
            return head;
        
        int n = 1;
        auto ptr = head;
        for ( ; ptr->next; ++n, ptr = ptr->next);
        
        // Reduce k to the range [0, n - 1]
        if (!(k %= n))
            return head;
        
        ptr->next = head;

        // Find the n - kth node from the front
        for (int i = 0; i < n - k; ++i, ptr = ptr->next);
        
        auto new_head = ptr->next;
        ptr->next = nullptr;
        
        return new_head;
    }
};
