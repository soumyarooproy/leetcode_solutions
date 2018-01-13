# 01/13/2018, TLE
# Time  : O(n!)
# Space : O(1)
class Solution:
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """        
        def swap(A, i, j):
            A[i], A[j] = A[j], A[i]

        def left_rotated(A, n):
            return A[n:] + A[:n]

        res = float('-inf')
        # Recursive function to generate all pairs of nums values uniquely
        def min_pair_sum_rec(index):
            nonlocal res
            # The last pair has just one choice; compute res and return
            if index == len(nums) - 2:
                res = max(res, sum(min(x, y) for x, y in zip(nums[::2], nums[1::2])))
                return
            # Swap elements in nums to create unique pairs (nums[index], nums[i])
            for i in range(index + 1, len(nums)):
                swap(nums, i, index + 1)
                min_pair_sum_rec(index + 2)
            # Left-rotate by 1 to restore nums[index + 1:] from before the for-loop above
            nums[index + 1:] = left_rotated(nums[index + 1:], 1)
            return
        
        min_pair_sum_rec(0)
        return res
