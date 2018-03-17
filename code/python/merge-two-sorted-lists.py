# 03/16/2018
# Time  : O(n + m)
# Space : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        new_pre_head = ListNode(0)
        node = new_pre_head
        
        # Use two-pointer technique as long as neither list is exhausted
        while l1 and l2:
            if l1.val <= l2.val:
                node.next = l1
                l1 = l1.next
            else:
                node.next = l2
                l2 = l2.next
            node = node.next
        
        # Attach the remaining nodes of the list that is not exhausted
        node.next = l2 if not l1 else l1
        
        return new_pre_head.next
