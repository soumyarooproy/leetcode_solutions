# 02/07/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def is_bst(root):
            if not root:
                return True, float('inf'), float('-inf')
            left_is_bst, left_min, left_max = is_bst(root.left)
            right_is_bst, right_min, right_max = is_bst(root.right)
            if left_is_bst and right_is_bst and left_max < root.val < right_min:
                return True, min(root.val, left_min), max(root.val, right_max)
            return False, None, None

        return is_bst(root)[0]
