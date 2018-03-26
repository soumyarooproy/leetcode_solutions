# Date  : 3/25/2018
# Time  : O(n**2)
# Space : O(n)
# Notes : Sort; use a set to uniqify

class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def two_sum(i):
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s == 0:
                    res.add((nums[i], nums[l], nums[r]))
                    l += 1
                    r -= 1
                elif s < 0:
                    l += 1
                else:
                    r -= 1

        nums.sort()
        res = set()
        for i in range(len(nums)):
            two_sum(i)
        return list(res)
