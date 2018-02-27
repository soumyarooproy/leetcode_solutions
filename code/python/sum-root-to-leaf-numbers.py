# 02/26/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        sum = 0
        path_nums = []
        def sum_numbers(root):
            nonlocal sum
            if not root:
                return
            if not root.left and not root.right:
                sum += int(''.join(str(x) for x in path_nums) if path_nums else 0)*10 + root.val
                return
            path_nums.append(root.val)
            sum_numbers(root.left)
            sum_numbers(root.right)
            path_nums.pop()
        
        sum_numbers(root)
        return sum
