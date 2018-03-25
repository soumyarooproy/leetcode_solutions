# Date  : 03/25/2018
# Time  : O(n)
# Space : O(m), number of distinct items

class Solution:
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        m = {}
        for i, n in enumerate(nums):
            if n in m and i - m[n] <= k:
                return True
            m[n] = i
        return False
