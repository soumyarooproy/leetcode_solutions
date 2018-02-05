# 87 ms, 01/25/2018
# Time  : O(n)
# Space : O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        paths = []
        path_so_far = []
        
        def path_sum(root, rem_sum, depth=0):
            nonlocal path_so_far, paths
            
            if not root:
                return

            # Update remaining sum and path so far
            rem_sum -= root.val
            path_so_far.append(root.val)
            
            # If leaf node, append path_so_far if remaining sum is 0
            # else look into the children
            if not root.left and not root.right:
                if not rem_sum:
                    paths.append(path_so_far[:])
            else:
                path_sum(root.left, rem_sum, depth + 1)
                path_sum(root.right, rem_sum, depth + 1)

            # Pop current node from path_so_far before returning to
            # parent node 
            path_so_far.pop()
            return
        
        path_sum(root, sum)
        return paths
