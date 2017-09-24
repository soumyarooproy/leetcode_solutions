// 3 ms, 09/22/2017
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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        auto pre_head = ListNode(0);
        pre_head.next = head;
        auto tail = &pre_head;
        auto count = 1;
        for ( ; count < m; ++count)
            tail = tail->next;
        auto first = tail->next;
        auto node = first;
        for ( ; count <= n; ++count) {
            auto node_next = node->next;
            auto next_tail = tail->next;
            tail->next = node;
            node->next = next_tail;
            node = node_next;
        }
        if (first)
            first->next = node;
        return pre_head.next;
    }
};
