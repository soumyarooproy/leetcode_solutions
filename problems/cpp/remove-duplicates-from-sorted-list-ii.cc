// 6 ms, 09/21/2017
// Time  : O(n)
// Space : O(1)
// 3rd iteration - replace while-loop with do-while
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
        if (!head || !head->next)
            return head;
        ListNode pre_new_head(0);
        pre_new_head.next = head;
        auto tail = &pre_new_head;
        /*
          Invariants:
          - tail is last node in the (new) list with only unique elements
          - tail->next is the next node whose uniqueness determination is pending
        */
        auto it = head;
        do {
            it = it->next;
            if (!it || it->val != tail->next->val) {
                if (tail->next->next == it) // tail->next is unique
                    tail = tail->next;
                tail->next = it;
            }
        } while (it);
        return pre_new_head.next;
    }
};
/*------------------------------------------------------------------*/
// Redefined invariants - cleaner code 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode pre_new_head(0);
        pre_new_head.next = head;
        auto tail = &pre_new_head;
        /*
          Invariants:
          - tail is last node in the (new) list with only unique elements
          - tail->next is the next node whose uniqueness determination is pending
        */
        auto it = head->next;
        while (it) {
            if (it->val != tail->next->val) {
                if (tail->next->next == it)
                    tail = tail->next;
                tail->next = it;
            }
            it = it->next;
        }
        if (!tail->next->next)
            tail = tail->next;
        tail->next = nullptr;
        return pre_new_head.next;
    }
};
/*------------------------------------------------------------------*/
// First attempt - ugly code
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        ListNode pre_new_head(0);
        auto tail = &pre_new_head, node = head;
        bool is_duplicate = false;
        for (auto it = head->next; it ; it = it->next) {
            if (it->val != node->val) {
                if (!is_duplicate)
                    tail->next = node, tail = tail->next;
                node = it, is_duplicate = false;
            } else if (!is_duplicate) {
                is_duplicate = true;
            }
        }
        if (!is_duplicate)
            tail->next = node, tail = tail->next;
        tail->next = nullptr;
        return pre_new_head.next;
    }
};
