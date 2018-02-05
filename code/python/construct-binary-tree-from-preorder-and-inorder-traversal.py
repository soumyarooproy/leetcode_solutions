# 98 ms, 02/04/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        # Construct {node: its index in inorder} map
        node2inorder = {x : i for i, x in enumerate(inorder)}

        def tree(start_p, end_p, start_i, end_i):
            if not start_p < end_p or not start_i < end_i:
                return None
            root_key = preorder[start_p]
            root_in_inorder = node2inorder[root_key]
            left_tree_size = root_in_inorder - start_i

            node = TreeNode(root_key)
            node.left = tree(start_p + 1, start_p + 1 + left_tree_size, start_i, root_in_inorder)
            node.right = tree(start_p + 1 + left_tree_size, end_p, root_in_inorder + 1, end_i)
            return node

        return tree(0, len(preorder), 0, len(inorder))
