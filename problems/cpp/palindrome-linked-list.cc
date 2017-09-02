// 32 ms, 09/02/2017
// 22 ms if the input list is not restored to original
// Fastest on leetcode 18 ms, also does not restore the input list
ListNode* reverse_list(ListNode* head)
{
    ListNode dummy_head(0);
    while (head) {
        auto saved_head_next = head->next;
        head->next = dummy_head.next;
        dummy_head.next = head;
        head = saved_head_next;
    }
    return dummy_head.next;
}

bool isPalindrome(ListNode* head)
{
    // Reverse the second half of the list and compare the
    // nodes in tandem; restore the list before returning

    // Find the mid point
    ListNode dummy_head(0);
    dummy_head.next = head;
    auto fast = &dummy_head, slow = fast;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow == fast) // the list is <2 nodes long
        return true;

    // Reverse the list
    auto rev_head = reverse_list(slow->next);
    slow->next = nullptr;

    // Check palindromicity
    bool is_palindrome = true;
    for (auto iter1 = head, iter2 = rev_head; iter1 && iter2; iter1 = iter1->next, iter2 = iter2->next)
        if (iter1->val != iter2->val) {
            is_palindrome = false;
            break;
        }

    // Restore the original list
    slow->next = reverse_list(rev_head);

    return is_palindrome;
}
