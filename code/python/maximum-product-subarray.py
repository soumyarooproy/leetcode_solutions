# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n) this implementation; can easily be made O(1)

class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # N[i] stores the min product, -ve if one exists, with A[i] as the last element
        # P[i] stores the max product, +ve if one exists, with A[i] as the last element
        N, P = [1], [1]
        for x in nums:
            p_last, n_last = P[-1], N[-1]
            P.append(max(n_last * x, x) if x < 0 else max(p_last * x, x))
            N.append(min(p_last * x, x) if x < 0 else min(n_last * x, x))

        return max(P[1:])
