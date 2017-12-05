// 32 ms, 09/01/2017
void advance_head(ListNode **head, int num)
{
    for (; num; *head = (*head)->next, --num);
}

int count_nodes(ListNode *head)
{
    int count = 0;
    for (; head; head = head->next, ++count);
    return count;
}

ListNode *getIntersectionNode(ListNode *head_a, ListNode *head_b)
{
    // Count the number of nodes in each list
    int count_a = count_nodes(head_a), count_b = count_nodes(head_b);
    
    // Bring head_a and head_b at the same distance from the end(s) 
    if (count_a > count_b)
        advance_head(&head_a, count_a - count_b);
    else if (count_b > count_a)
        advance_head(&head_b, count_b - count_a);

    // head_a and head_b are at the same distance from the end(s)
    while (head_a) {
        if (head_a == head_b)
            return head_a;
        head_a = head_a->next, head_b = head_b->next;
    }

    return nullptr;
}
