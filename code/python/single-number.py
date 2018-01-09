import functools, operator
class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Compute bitwise XOR of all the elements in nums
        return functools.reduce(operator.xor, nums, 0)
