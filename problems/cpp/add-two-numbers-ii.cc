// 49 ms, 10/07/2017
// Time  : O(n)
// Space : O(1)
// The inputs are modified (lists are reversed) in-place
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
        // Reverse the lists
        l1 = reversed(l1), l2 = reversed(l2);
        
        // Perform the addition, creating new nodes and reversing them
        // on the go
        ListNode pre_new_head(0);
        int carry = 0;
        while (l1 || l2) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            insert_after(&pre_new_head, new ListNode(sum % 10));
            carry = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry)
            insert_after(&pre_new_head, new ListNode(1));
        
        // Restore the original lists
        reversed(l1), reversed(l2);
        
        return pre_new_head.next;
    }
private:
    void insert_after(ListNode* target, ListNode* node)
    {
        node->next = target->next, target->next = node;
    }
    ListNode* extract_after(ListNode* target)
    {
        auto tmp = target->next;
        target->next = tmp->next;
        return tmp;
    }
    ListNode* reversed(ListNode* head)
    {
        ListNode pre_head(0);
        pre_head.next = head;
        while (head && head->next) {
            insert_after(&pre_head, extract_after(head));
        }
        return pre_head.next;
    }
};
/*------------------------------------------------------------*/
// Space : O(n)
// Use stacks to reverse the order of the digits
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        // Use a stack to access the digits in reverse order
        // if the lists are not allowed to be modified
        stack<int> s1, s2;
        for ( ; l1; s1.push(l1->val), l1 = l1->next);
        for ( ; l2; s2.push(l2->val), l2 = l2->next);
        
        int carry = 0;
        ListNode pre_new_head(0);
        while (!s1.empty() || !s2.empty()) {
            int sum = (!s1.empty() ? s1.top() : 0) + (!s2.empty() ? s2.top() : 0) + carry;
            insert_after(&pre_new_head, new ListNode(sum % 10));
            carry = sum / 10;
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();
        }
        if (carry)
            insert_after(&pre_new_head, new ListNode(1));
        
        return pre_new_head.next;
    }
private:
    void insert_after(ListNode* target, ListNode* node)
    {
        node->next = target->next, target->next = node;
    }
    ListNode* extract_after(ListNode* target)
    {
        auto tmp = target->next;
        target->next = tmp->next;
        return tmp;
    }
};
