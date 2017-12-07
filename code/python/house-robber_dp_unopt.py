# 52 ms, 12/06/2017
# Time  : O(n^2)
# Space : O(n)
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        # M[i] = Max value robbed if i-th house is robbed
        # Set M[-1] and M[0]
        M = [0, nums[0]]
        for x in nums[1:]:
            M.append(max(M[:-1]) + x)

        return max(M[1:])
