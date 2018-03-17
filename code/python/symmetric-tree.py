# 03/16/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def is_mirror(root1, root2):
            if not root1:
                return not root2
            if not root2:
                return False
            return root1.val == root2.val and is_mirror(root1.left, root2.right) and is_mirror(root1.right, root2.left)
        
        return not root or is_mirror(root.left, root.right)
