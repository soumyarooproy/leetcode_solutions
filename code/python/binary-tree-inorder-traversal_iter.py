# 61 ms, 02/02/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # Inorder - Left Root Right

        # Iterative implementation
        def inorder_iter(root):
            nonlocal sequence
            stack = []
            while stack or root:
                if root:
                    stack += root,
                    root = root.left
                else:
                    root = stack.pop()
                    sequence += root.val,
                    root = root.right
            return
        
        sequence = []
        inorder_iter(root)
        return sequence
