# 02/15/2018
# Time  : O(2**n)
# Space : O(2**n)
class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        """
        Enumerate all integers in the range [0, 2**n - 1] and for each integer, create a set by
        including nums[i] if the ith bit in the integer is '1'; include that set in the powerset
        """
