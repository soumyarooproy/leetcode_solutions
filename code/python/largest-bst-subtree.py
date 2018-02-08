# 122 ms, 02/07/2018 (62 ms, if tuple used instead of namedtuple)
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections

class Solution(object):
    def largestBSTSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        BstInfo = collections.namedtuple('BstInfo', ['is_bst', 'min_key', 'max_key', 'largest_bst'])
        def largest_bst(root):
            if not root:
                return BstInfo(True, float('+inf'), float('-inf'), 0)
            left = largest_bst(root.left)
            right = largest_bst(root.right)
            if left.is_bst and right.is_bst and left.max_key < root.val < right.min_key:
                return BstInfo(True,
                               min(root.val, left.min_key),
                               max(root.val, right.max_key),
                               left.largest_bst + right.largest_bst + 1)
            return BstInfo(False, None, None, max(left.largest_bst, right.largest_bst))

        return largest_bst(root).largest_bst
