# Date  : 03/20/2018
# Time  : O(n)
# Space : O(p), p is the max number of leaves at any level (worst O(n))

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalOrder(self, root):
        res = collections.deque()                          # deque because we want efficient appends at both ends of res
        q = collections.deque([(root, 0)] if root else []) # BFS queue
        min_col = 0
        while q:
            node, col = q.popleft()
            
            # If col is the min or max column seen so far, add a new list for it
            if col < min_col:
                res.appendleft([])
                min_col = col
            elif col - min_col == len(res):
                res.append([])
            
            res[col - min_col].append(node.val)
            
            # Enqueue the node's children, if applicable
            if node.left:
                q.append((node.left, col - 1))
            if node.right:
                q.append((node.right, col + 1))
        return [row for row in res]
