# Date  : 03/17/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        leaves = []
        def thread_leaves(root):
            if not root:
                return -1
            height = 1 + max(thread_leaves(root.left), thread_leaves(root.right))
            if len(leaves) == height:
                leaves.append([])
            leaves[height].append(root.val)
            return height
        
        thread_leaves(root)
        return leaves
