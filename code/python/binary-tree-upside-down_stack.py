# Date  : 03/18/2018
# Time  : O(n)
# Space : O(h), h = O(n) in this case
# Notes : Refer to binary-tree-upside-down.py for recursive implementation

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def upsideDownBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        parents = []
        while root:
            parents.append(root)
            root = root.left

        new_root = parents[-1] if parents else None
        
        while parents:
            root = parents.pop()
            root.left = parents[-1].right if parents else None
            root.right = parents[-1] if parents else None

        return new_root
