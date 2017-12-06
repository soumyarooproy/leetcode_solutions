# 49 ms, 12/05/2017
# Time  : O(n), 2 passes
# Space : O(n)
class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        M = [nums[0]]
        for x in nums[1:]:
            M.append(max(0, M[-1]) + x)
        return max(M)
