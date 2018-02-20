# 02/20/2018
# Time  : O(n)
# Space : O(n)
# This is an optimized version of maximum-swap_dp.py

class Solution:
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        import itertools
        
        # Convert num into a list of chars
        A = [c for c in str(num)]
        
        # Compute suffix max for A
        suff_max = list(reversed(list(itertools.accumulate(reversed(A), max))))
        
        # Compute char -> farthest appearance in A
        last = {x : i for i, x in enumerate(A)}
        
        # Find the first mismatch between A and suff_max
        try:
            i, x, y = next((i, x, y) for i, (x, y) in enumerate(zip(A, suff_max)) if x != y)
        except StopIteration: # No mismatch, num is already max
            return num
        
        # Swap the A[i] with the farthest appearance of y in A
        A[i], A[last[y]] = A[last[y]], A[i]
        
        return int(''.join(A))
