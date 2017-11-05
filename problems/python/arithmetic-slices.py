// 49 ms, 11/04/2017
// Time  : O(n)
// Space : O(1)
class Solution:
    def numberOfArithmeticSlices(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        total_count, this_count = 0, 0
        for i in range(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                this_count += 1
                total_count += this_count
            else:
                this_count = 0
        return total_count
