# 221 ms, 02/04/2018
# Time  : O(n)
# Space : O(h)
class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        stack = []
        for x in nums:
            node = TreeNode(x)
            while stack and x > stack[-1].val:
                node.left = stack.pop()
            if stack:
                stack[-1].right = node
            stack.append(node)
        return stack[0]
