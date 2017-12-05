// 9 ms, 09/28/2017
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
    ListNode *detectCycle(ListNode *head)
    {
        auto slow = head, fast = head;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast)
                    slow = slow->next, fast = fast->next;
                return slow;
            }
        }
        return nullptr;
    }
};
