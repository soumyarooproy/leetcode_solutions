# 03/06/2018
# Time  : O(n^2)
# Space : O(n)

class Solution:
    from functools import lru_cache
    @lru_cache(maxsize=None)
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        return sum(self.numTrees(key) * self.numTrees(n - key - 1) for key in range(n)) or 1
