# 83 ms, 02/06/2018
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
        def are_keys_within_bounds(root, lb, ub):
            if not root:
                return True
            return (lb < root.val < ub
                    and are_keys_within_bounds(root.left, lb, root.val)
                    and are_keys_within_bounds(root.right, root.val, ub))
        
        return are_keys_within_bounds(root, float('-inf'), float('+inf'))
