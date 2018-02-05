# 56 ms, 02/04/2018
# Time  : O(N), N is O(lg K)
# Space : O(N)
class Solution:
    def kthGrammar(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: int
        """
        def soln_recur(N, K): # K is 0-indexed
            if N == 1:    
                return 0
            par = soln_recur(N - 1, K//2)
            return par if (K % 2 == 0) else int(not par)

        # N and K are both 1-indexed
        return soln_recur(N, K - 1)
