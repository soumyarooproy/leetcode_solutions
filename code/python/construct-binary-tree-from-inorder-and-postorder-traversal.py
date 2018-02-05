# 102 ms, 02/04/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        # Construct {node: its index in inorder} map
        node2inorder = {x : i for i, x in enumerate(inorder)}

        def tree(start_p, end_p, start_i, end_i, depth = 0):
            if not start_p < end_p or not start_i < end_i:
                return None
            root_key = postorder[end_p - 1]
            root_in_inorder = node2inorder[root_key]
            right_tree_size = end_i - 1 - root_in_inorder

            node = TreeNode(root_key)
            node.left = tree(start_p, end_p - 1 - right_tree_size, start_i, root_in_inorder, depth + 1)
            node.right = tree(end_p - 1 - right_tree_size, end_p - 1, root_in_inorder + 1, end_i, depth + 1)
            return node

        return tree(0, len(postorder), 0, len(inorder))
