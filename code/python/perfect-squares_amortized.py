# 172 ms, 12/08/2017
# Time  : O(sqrt(n)) amortized (?), O(n*sqrt(n)) worst case
# Space : O(n)
# Refer to https://discuss.leetcode.com/topic/23812/static-dp-c-12-ms-python-172-ms-ruby-384-ms
class Solution:
    _N = [0,1,2,3]
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        N = self._N
        while len(N) <= n:
            i = len(N)
            N += [1 + min(N[i - j*j] for j in range(2, int(math.sqrt(i)) + 1))]
        return N[n]
