# Date  : 03/25/2018
# Time  : O(n)
# Space : O(1)

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy_head = ListNode(0)
        carry, tail = 0, dummy_head
        while l1 or l2:
            sum = carry + (l1.val if l1 else 0) + (l2.val if l2 else 0)
            tail.next = ListNode(sum % 10)
            tail = tail.next
            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
            carry = sum // 10
        
        if carry:
            tail.next = ListNode(carry)
        
        return dummy_head.next
