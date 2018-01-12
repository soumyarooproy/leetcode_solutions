# 01/12/2018, TLE
# Time  : O(n^2)
# Space : O(1)
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        A = height
        # Compute max over all (i, j) pairs
        return max((j - i) * min(A[i], A[j]) for i in range(len(A)) for j in range(i + 1, len(A)))
