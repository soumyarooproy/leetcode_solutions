# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

import collections

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        LcaInfo = collections.namedtuple('LcaInfo', ['lca', 'num_found'])
        def lca_recur(root, p, q):
            if not root:
                return LcaInfo(None, 0)
            # Inspect the left subtree and propagate lca up if valid
            left_lca_info = lca_recur(root.left, p, q)
            if left_lca_info.lca:
                return left_lca_info
            # Inspect the right subtree and propagate lca up if valid
            right_lca_info = lca_recur(root.right, p, q)
            if right_lca_info.lca:
                return right_lca_info
            # Finally, determine if current root is the lca
            num_found = left_lca_info.num_found + right_lca_info.num_found + int(root is p) + int(root is q)
            return LcaInfo(root if num_found == 2 else None, num_found)
        
        return lca_recur(root, p, q).lca
