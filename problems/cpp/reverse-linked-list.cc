// 9 ms, 09/04/2017
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
