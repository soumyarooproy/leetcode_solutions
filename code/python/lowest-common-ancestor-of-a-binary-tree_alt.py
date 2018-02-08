# 109 ms, 02/07/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        def lca_recur(root, p, q):
            if not root:
                return None
            if root is p or root is q:
                return root
            left = lca_recur(root.left, p, q)
            right = lca_recur(root.right, p, q)
            return root if left and right else left if left else right if right else None

        return lca_recur(root, p, q)
