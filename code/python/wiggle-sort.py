# 02/28/2018
# Time  : O(n)
# Space : O(1)
# Notes : https://stackoverflow.com/questions/27454385/permute-array-to-make-it-alternate-between-increasing-and-decreasing

class Solution:
    def wiggleSort(self, A):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        ge = True
        for i in range(1, len(A)):
            if not ge and A[i - 1] < A[i] or ge and A[i - 1] > A[i]:
                # Swap A[i] and A[i - 1]
                A[i - 1], A[i] = A[i], A[i - 1]
            ge = not ge
