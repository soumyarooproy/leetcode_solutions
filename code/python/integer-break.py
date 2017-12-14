"""
65 ms, 12/14/2017
Time  : O(n^2)
Space : O(n)
"""
class Solution:
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        M = [0, 1]
        for i in range(2, n + 1):
            M += max(j * max(i - j, M[i - j]) for j in range(1, i)),
        return M[-1]
