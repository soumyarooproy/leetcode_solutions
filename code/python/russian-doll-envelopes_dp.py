"""
TLE, 12/17/2017
Time  : O(n^2)
Space : O(n)
"""
class Solution:
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        A = envelopes
        if not A:
            return 0
        """
            Sort envelopes by size
            For each envelope x:
                max number of envelopes that can fit in x
                    = 1 + max{max number of envelopes that can fit in y, y being all the envelopes smaller than x}
        """
        A.sort()
        M = [1]
        for i in range(1, len(A)):
            M += 1 + max((M[j] for j in range(i) if A[i][0] > A[j][0] and A[i][1] > A[j][1]), default=0),
        return max(M)
