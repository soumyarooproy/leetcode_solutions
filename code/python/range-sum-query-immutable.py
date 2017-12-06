# 75 ms, 12/06/2017
# Time  : O(1) amortized
# Space : O(n)
from itertools import accumulate

class NumArray:

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.prefix_sum = [0]
        self.prefix_sum.extend(list(accumulate(nums)))

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.prefix_sum[j + 1] - self.prefix_sum[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
