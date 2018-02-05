# 60 ms, 02/02/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # Preorder - Root Left Right
        
        # Recursive implementation
        def preorder_recur(root):
            nonlocal sequence
            if not root:
                return
            sequence += root.val,
            preorder_recur(root.left)
            preorder_recur(root.right)
            return

        sequence = []
        preorder_recur(root)
        return sequence
