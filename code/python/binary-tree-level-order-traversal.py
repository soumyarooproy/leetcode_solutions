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
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        levels = []
        def inorder(root, depth):
            if not root:
                return
            if len(levels) == depth:
                levels.append([])
            levels[depth].append(root.val)
            inorder(root.left, depth + 1)
            inorder(root.right, depth + 1)
        
        inorder(root, 0)
        return levels
