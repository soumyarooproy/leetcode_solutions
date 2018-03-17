# 03/17/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findSecondMinimumValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def find_min_two(root):
            if not root:
                return float('inf'), float('inf')
            min1 =  [x for x in find_min_two(root.left)  if x > root.val]
            min1 += [x for x in find_min_two(root.right) if x > root.val]
            return root.val, min(min1)
        
        min0, min1 = find_min_two(root)
        
        return min1 if min1 != float('inf') else -1
