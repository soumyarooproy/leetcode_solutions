# Date  : 03/17/2018
# Time  : O(n)
# Space : O(h)
# Notes : This solution uses BFS

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
        if not root:
            return []
        q, res = [root], []
        while q:
            res.append(max(x.val for x in q))
            q = [child for x in q for child in (x.left, x.right) if child]
        return res
