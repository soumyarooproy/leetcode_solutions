# 02/26/2018
# Time  : O(n)
# Space : O(n + h), for memoization + recursion = O(n)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # Maximum path sum in a tree rooted at node either passes through the root or is in one of its subtrees
        #     M(node) = max(max_path_sum_with_node(node), M(node.left), M(node.right))
        #
        # max_path_sum_with_node(node) = node.key
        #                                + max_path_sum_starting_at_node(node.left)
        #                                + max_path_sum_starting_at_node(node.right)
        #
        # max_path_sum_starting_at_node(node) = node.key
        #                                      + max([0,
        #                                             max_path_sum_starting_at_node(node.left),
        #                                             max_path_sum_starting_at_node(node.right)])
        #
        # Use memoization to speed up lookups
        
        max_path_sum_starting_at_node = {None : 0}
        def max_path_sum(root):
            if not root:
                return float('-inf')

            # Make these recursive calls so that max_path_sum_starting_at_node map gets populated
            max_path_sum_left_subtree, max_path_sum_right_subtree = max_path_sum(root.left), max_path_sum(root.right)
            
            # Compute the max sum with root in the path
            max_path_sum_starting_left = max(0, max_path_sum_starting_at_node[root.left])
            max_path_sum_starting_right = max(0, max_path_sum_starting_at_node[root.right])
            max_path_sum_starting_at_node[root] = root.val + max(max_path_sum_starting_left, max_path_sum_starting_right)
            
            # Max sum path in the subtree is either through the root or in one of its left or right subtrees
            return max([root.val + max_path_sum_starting_left + max_path_sum_starting_right,
                        max_path_sum_left_subtree,
                        max_path_sum_right_subtree])
        
        return max_path_sum(root)
