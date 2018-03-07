# 03/06/2018
# Time  : O(n^2)
# Space : O(n^2)
# Notes : Refer to unique-binary-search-trees_memoized_opt.py for O(n) space implementation

class Solution:
    from functools import lru_cache
    @lru_cache(maxsize=None)
    def numTrees(self, high, low=1):
        """
        :type n: int
        :rtype: int
        """
        return sum(self.numTrees(key - 1, low) * self.numTrees(high, key + 1) for key in range(low, high + 1)) or 1
