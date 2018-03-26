# Date  : 03/25/2018
# Time  : O(n)
# Space : O(lg(n))

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def build_bst(index_left, index_past_right):
            if index_left == index_past_right:
                return None
            index_root = (index_left + index_past_right) // 2
            root = TreeNode(nums[index_root])
            root.left = build_bst(index_left, index_root)
            root.right = build_bst(index_root + 1, index_past_right)
            return root

        return build_bst(0, len(nums))
