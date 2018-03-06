# 03/06/2018
# Time  : O(n*m)
# Space : O(n*m), where m is the number of binary trees of n nodes
# Notes : Code based on https://leetcode.com/problems/unique-binary-search-trees-ii/discuss/31495/Should-be-6-Liner

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def tree_node(key, left, right):
            tree = TreeNode(key)
            tree.left = left
            tree.right = right
            return tree
        
        from functools import lru_cache
        @lru_cache(maxsize=None)
        def gen_trees(start_key, stop_key):
            return [tree_node(root_key, left, right)
                    for root_key in range(start_key, stop_key + 1)
                    for left in gen_trees(start_key, root_key - 1)
                    for right in gen_trees(root_key + 1, stop_key)] or [None]
        
        if not n:
            return []
        return gen_trees(1, n)
