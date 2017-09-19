// 42 ms, 09/18/2017
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode new_pre_head(0);
        auto result = &new_pre_head;
        int carry = 0;
        while (l1 || l2) {
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            result = result->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry)
            result->next = new ListNode(1), result = result->next;
        result->next = nullptr;
        return new_pre_head.next;
    }
};
/*-------------------------------------------------------------------------*/
// Faster code - likely to exhibit better (hardware) branch prediction
// Two separate loops - first to add the digits as long as both the lists are
// non-empty and the other to propagate the carry through the leftover list,
// if there happens to be one
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode new_pre_head(0);
        auto result = &new_pre_head;
        
        // Perform ripple-carry addition
        int carry = 0;
        // Add digits as long as both lists are non-empty
        while (l1 && l2) {
            int sum = carry + l1->val + l2->val;
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            result = result->next, l1 = l1->next, l2 = l2->next;
        }

        if (!l1)
            l1 = l2;
        // Only at most one list is non-empty now - just propagate the carry
        while (l1) {
            int sum = carry + l1->val;
            result->next = new ListNode(sum % 10);
            carry = sum / 10;
            result = result->next, l1 = l1->next;
        }

        if (carry)
            result->next = new ListNode(1), result = result->next;
        result->next = nullptr;
        return new_pre_head.next;
    }
};
