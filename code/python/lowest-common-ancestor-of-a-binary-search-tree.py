# 102 ms, 02/07/2018
# Time  : O(h)
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
        if not root or not p or not q:
            return root

        def lca_recur(root, s, l):
            return (lca_recur(root.right, s, l) if root.val < s.val
                    else lca_recur(root.left, s, l) if root.val > l.val
                    else root)
        # Make sure p has the smaller key
        if p.val > q.val:
            p, q = q, p
        return lca_recur(root, p, q)
