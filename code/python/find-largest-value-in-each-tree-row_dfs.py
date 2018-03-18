# Date  : 03/17/2018
# Time  : O(n)
# Space : O(h)
# Notes : This solution uses DFS

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        def max_value(root, depth):
            if not root:
                return
            if len(res) == depth:
                res.append(float('-inf'))
            res[depth] = max(root.val, res[depth])
            max_value(root.left, depth + 1)
            max_value(root.right, depth + 1)
        
        max_value(root, 0)
        return res
