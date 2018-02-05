# 607 ms, 02/04/2018
# Time  : O(n^2)
# Space : O(h)
class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def tree(start, end):
            if not end > start:
                return None
            max_i = nums.index(max(nums[start : end]))
            node = TreeNode(nums[max_i])
            left_tree = tree(start, max_i)
            right_tree = tree(max_i + 1, end)
            node.left, node.right = left_tree, right_tree
            return node
        return tree(0, len(nums))
