# 79 ms, 12/05/2017
# Time  : O(n), 1 pass
# Space : O(1)
# Refinement of maximum-subarray.py
class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        sum, max_sum = nums[0], nums[0]
        for x in nums[1:]:
            sum = max(0, sum) + x
            max_sum = max(max_sum, sum)
        return max_sum
