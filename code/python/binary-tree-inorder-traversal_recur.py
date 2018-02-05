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
        
        # Recursive implementation
        def inorder_recur(root):
            nonlocal sequence
            if not root:
                return
            inorder_recur(root.left)
            sequence += root.val,
            inorder_recur(root.right)
            return
        
        sequence = []
        inorder_iter(root)
        return sequence
