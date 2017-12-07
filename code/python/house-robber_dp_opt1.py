# 48 ms, 12/06/2017
# Time  : O(n)
# Space : O(n)
# Refer to house-robber_dp_unopt.py
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        # M[i] = Max value robbed from 0..i houses; M[-1] = 0
        # Set M[-1] and M[0]
        M = [0, nums[0]]
        for x in nums[1:]:
            M.append(max(M[-1], M[-2] + x))

        return M[-1]
