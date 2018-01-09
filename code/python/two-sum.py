# 12/26/2017, 52 ms
# Time  : O(n)
# Space : O(n)
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) < 2:
            return []

        # Store each number and its index as a key-value pair in a dict
        # and look for the value (target - x) for each x in nums 
        seen = {nums[0] : 0}
        for i in range(1, len(nums)):
            if (target - nums[i]) in seen:
                return [seen[target - nums[i]], i]
            seen[nums[i]] = i
