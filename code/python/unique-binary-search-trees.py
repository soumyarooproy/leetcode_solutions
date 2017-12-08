# 46 ms, 12/09/2017
# Time  : O(n^2)
# Space : O(n)
# This is a bottom-up DP refinement of the brute force approach in unique-binary-search-trees_brute.py
class Solution:
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        N = [1, 1]                            # n values of 0 and 1, 0 is a base case for DP implementation
        for i in range(2, n + 1):             # i iterates over 2..n
            N.append(0)
            for r in range(i):                # r iterates over 0..1, then 0..2, then 0..3, etc.
                N[-1] += N[r] * N[i - r - 1]
        return N[-1]
