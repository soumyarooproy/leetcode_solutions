# TLE, 12/08/2017
# Time  : O(n*sqrt(n))
# Space : O(n)
# Preserve N across various testcases on the Leetcode OJ to avoid TLE (perfect-squares_amortized.py)
class Solution:
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        N = [0,1,2,3]
        while len(N) <= n:
            i = len(N)
            N += [1 + min(N[i - j*j] for j in range(2, int(math.sqrt(i)) + 1))]
        return N[n]
