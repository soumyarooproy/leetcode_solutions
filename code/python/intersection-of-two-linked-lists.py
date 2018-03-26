# Date  : 03/25/2018
# Time  : O(n)
# Space : O(1)

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        def len(head):
            count = 0
            while head:
                count += 1
                head = head.next
            return count

        len1, len2 = len(headA), len(headB)

        # if listB is longer than listA, swap them
        if len2 > len1:
            headA, headB = headB, headA

        # Advance listA head so that it is at the same distance
        # from the end as listB head is from its end
        diff = abs(len1 - len2)
        for _ in range(diff):
            headA = headA.next

        # Now advance both list heads in tandem
        while headA:
            if headA is headB:
                break
            headA, headB = headA.next, headB.next

        return headA
