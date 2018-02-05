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

        # Iterative implementation
        def preorder_iter(root):
            nonlocal sequence
            stack = [root]
            while stack:
                root = stack.pop()
                if root:
                    sequence += root.val,
                    stack += [root.right, root.left]
            return

        sequence = []
        preorder_iter(root)
        return sequence
