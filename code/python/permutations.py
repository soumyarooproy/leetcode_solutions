# 03/16/2018
# Time  : O(2**n)
# Space : O(n)

class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        def permute_recursive(index):
            if index == len(nums):
                result.append(copy.copy(nums))
                return
            for i in range(index, len(nums)):
                nums[i], nums[index] = nums[index], nums[i]
                permute_recursive(index + 1)
                nums[i], nums[index] = nums[index], nums[i]
        
        permute_recursive(0)
        return result
