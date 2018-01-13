# 01/13/2018, 180 ms
# Time  : O(n*lg(n))
# Space : O(1)
class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        return sum(sorted(nums)[::2])
