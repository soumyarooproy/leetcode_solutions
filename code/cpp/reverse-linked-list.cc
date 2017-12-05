// 9 ms, 09/04/2017
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
ListNode* reverseList(ListNode* head)
{
    ListNode dummy_head(0);

    while (head) {
        auto head_next = head->next;
        head->next = dummy_head.next;
        dummy_head.next = head;
        head = head_next;
    }

    return dummy_head.next;
}
/*-----------------------------------------------------------------*/
// Recursive solution
// Space : O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head)
            return head;
        return reverse_recursive(head).first;
    }
private:
    pair<ListNode*, ListNode*> reverse_recursive(ListNode* head)
    {
        if (!head->next)
            return make_pair(head, head);
        auto list_bounds = reverse_recursive(head->next);
        list_bounds.second->next = head;
        head->next = nullptr;
        return make_pair(list_bounds.first, head);
    }
};
