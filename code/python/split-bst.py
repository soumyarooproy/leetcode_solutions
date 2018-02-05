# 61 ms, 02/04/2018
# Time  : O(h)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def splitBST(self, root, V):
        """
        :type root: TreeNode
        :type V: int
        :rtype: List[TreeNode]
        """
        if not root:
            return [None, None]
        
        # If key is smaller than root, the split point is in the left subtree
        if V < root.val:
            trees = self.splitBST(root.left, V)
            root.left = trees[1]
            return [trees[0], root]

        # Otherwise, the split point is in the right subtree
        trees = self.splitBST(root.right, V)
        root.right = trees[0]
        return [root, trees[1]] 
