// 29 ms, 09/02/2017
ListNode* removeElements(ListNode* head, int val)
{
    ListNode dummy_head(0);
    dummy_head.next = head;
    head = &dummy_head;

    while (head->next) {
        while (head->next && head->next->val != val)
            head = head->next;
        if (!head->next)
            break;
        auto ptr = head->next;
        head->next = head->next->next;
        delete ptr;
    }

    return dummy_head.next;
}
