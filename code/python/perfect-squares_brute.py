# TLE, 12/08/2017
# Time  : O(c**n)?
# Space : O(1)
class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n < 4:
            return n
        min_count = n # all 1's
        for i in range(int(math.sqrt(n)), 1, -1):
            min_count = min(min_count, self.numSquares(n - i**2))
        return 1 + min_count
