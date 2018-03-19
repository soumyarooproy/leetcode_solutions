# Date  : 03/18/2018
# Time  : O(n)
# Space : Space(1)

class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        # Compute prefix products
        result = [1] * len(nums)
        for i in range(1, len(nums)):
            result[i] = result[i - 1] * nums[i - 1]

        # Compute suffix products and multiply with previously computed prefix products
        suff_prod = 1
        for i in range(len(nums) - 1, 0, -1):
            suff_prod *= nums[i]
            result[i - 1] *= suff_prod

        return result
