// 6 ms, 09/28/2017
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
    ListNode* partition(ListNode* head, int x)
    {
        auto pre_new_head1 = ListNode(0), pre_new_head2 = ListNode(0);
        auto tail1 = &pre_new_head1, tail2 = &pre_new_head2;

        while (head) {
            if (head->val < x)
                tail1->next = head, tail1 = head;
            else
                tail2->next = head, tail2 = head;
            head = head->next;
        }
        tail2->next = nullptr;
        tail1->next = pre_new_head2.next;
        return pre_new_head1.next;
    }
};
