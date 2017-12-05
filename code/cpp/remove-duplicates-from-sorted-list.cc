// 9 ms, 09/12/2017
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head)
            return head;
        auto tail = head;
        for (ListNode* node = head->next, *node_next; node != nullptr; node = node_next) {
            node_next = node->next;
            if (node->val != tail->val) {
                if (tail->next != node)
                    tail->next = node;
                tail = node;
            } else
                delete(node);
        }
        tail->next = nullptr;
        return head;
    }
};
/*-------------------------------------------------------------------*/
// TODO  : Cleaner solution on leetcode
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr=head;
        while (curr) {
            if (curr->next && curr->next->val==curr->val) {
                ListNode *tmp=curr->next;
                curr->next=curr->next->next;
                delete tmp;
            } else {
                curr=curr->next;
            }
        }
        return head;
    }
};
