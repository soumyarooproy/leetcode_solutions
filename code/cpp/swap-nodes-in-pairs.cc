// 3 ms, 09/18/2017
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
    ListNode* swapPairs(ListNode* head) 
    {
        auto dummy_pre_head = ListNode(0);
        dummy_pre_head.next = head;
        for (auto it = head, tail = &dummy_pre_head; it && it->next; tail = tail->next->next, it = tail->next) {
            auto it_next_next = it->next->next;
            tail->next = it->next;
            it->next->next = it;
            it->next = it_next_next;
        }
        return dummy_pre_head.next;
    }
};
