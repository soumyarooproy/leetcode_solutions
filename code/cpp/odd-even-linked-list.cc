// 16 ms, 09/17/2017
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
    ListNode* oddEvenList(ListNode* head)
    {
        ListNode head_odd(0);
        ListNode head_even(0);
        
        auto tail_odd = &head_odd, tail_even = &head_even;
        auto it = head;
        for (it = head; it && it->next; it = it->next->next, tail_odd = tail_odd->next, tail_even = tail_even->next) {
            tail_odd->next = it;
            tail_even->next = it->next;
        }
        if (it)
            tail_odd->next = it, tail_odd = tail_odd->next;
        tail_even->next = nullptr;
        
        tail_odd->next = head_even.next;
        return head_odd.next;
    }
};
