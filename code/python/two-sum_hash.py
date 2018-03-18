# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n)

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num2index = {}
        for i, x in enumerate(nums):
            diff = target - x
            if diff in num2index:
                return num2index[diff], i
            num2index[x] = i
        else:
            assert False, 'Should not have reached here'
