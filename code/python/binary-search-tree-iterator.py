# 88 ms, 02/06/2018
# Time  : O(n) for n hasnext()-next() call pairs; O(1) amortized
# Space : O(h)

# Definition for a  binary tree node
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):
    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self._stack = []
        while root:
            self._stack.append(root)
            root = root.left

    def hasNext(self):
        """
        :rtype: bool
        """
        return self._stack

    def next(self):
        """
        :rtype: int
        """
        ret_node = self._stack.pop()
        node = ret_node.right
        while node:
            self._stack.append(node)
            node = node.left
        return ret_node.val

# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
