# 62 ms, 02/02/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # Postorder - Left Root Right

        # Recursive implementation
        def postorder_recur(root):
            nonlocal sequence
            if not root:
                return
            postorder_recur(root.left)
            postorder_recur(root.right)
            sequence += root.val,
            return
        
        sequence = []
        postorder_recur(root)
        return sequence
