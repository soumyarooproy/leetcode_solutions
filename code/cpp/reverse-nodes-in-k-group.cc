// 23 ms, 10/08/2017
// Time  : O(n)
// Space : O(1)
// TODO  : Use recursion
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    struct reversal_info { ListNode* new_head; int num_reversed; };
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head)
            return head;

        ListNode pre_head(0);
        pre_head.next = head, head = &pre_head;
        auto prev_head = head;
        for (head = head->next; head; prev_head = head, head = head->next) {
            auto info = reversed_sublist(head, k);
            if (info.num_reversed < k) { // has to be the last sublist
                prev_head->next = reversed_sublist(info.new_head, k).new_head;
                break;
            }
            prev_head->next = info.new_head;
        }
        return pre_head.next;
    }
private:
    ListNode* extract_after(ListNode* node)
    {
        auto tmp = node->next;
        node->next = node->next->next;
        return tmp;
    }
    void insert_after(ListNode* node, ListNode* new_node)
    {
        new_node->next = node->next;
        node->next = new_node;
    }
    reversal_info reversed_sublist(ListNode* head, int k)
    {
        ListNode pre_head(0);
        pre_head.next = head;
        int i = 1;
        for ( ; i < k && head->next; ++i) {
            insert_after(&pre_head, extract_after(head));
        }
        return {pre_head.next, i};
    }
};
