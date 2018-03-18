# Date  : 03/18/2018
# Time  : O(n) - 2 passes
# Space : O(h)
# Notes : The problem description is incorrect in that the leaf level integers do not have
#         weight 1 -- only the leaf nodes with the max depth have weight 1; the others have
#         a weight of (tree height - depth), both height and depth being 1-indexed instead
#         of 0-indexed (https://stackoverflow.com/questions/2603692/)

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def depthSumInverse(self, nestedList):
        """
        :type nestedList: List[NestedInteger]
        :rtype: int
        """
        def get_height(nl, depth=0):
            return 1 + max((get_height(l.getList(), depth + 1) for l in nl if not l.isInteger()), default=0)

        def weighted_sum(nl, height):
            return sum(l.getInteger() * height if l.isInteger() else weighted_sum(l.getList(), height - 1) for l in nl)

        return weighted_sum(nestedList, get_height(nestedList))
