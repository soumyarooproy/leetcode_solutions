# 622 ms, 12/08/2017
# Time  : O(n*sqrt(n))
# Space : O(n)
# Memoized version of perfect-squares_brute.py
import functools
class Solution:
    @functools.lru_cache(None) # Decorator for memoization
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 4:
            return n
        min_count = n # all 1's
        for i in range(int(math.sqrt(n)), 1, -1):
            min_count = min(min_count, n // (i*i) + self.numSquares(n % (i*i)))
        return min_count
