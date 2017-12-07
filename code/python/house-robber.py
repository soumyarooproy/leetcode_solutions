# 49 ms, 12/06/2017
# Time  : O(n)
# Space : O(1)
# Refer to house-robber_dp_opt1.py
class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        max_rob_1, max_rob_2 = nums[0], 0
        for x in nums[1:]:
            max_rob_1, max_rob_2 = max(max_rob_1, max_rob_2 + x), max_rob_1
        
        return max_rob_1
