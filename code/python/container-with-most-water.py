# 01/12/2018, 108 ms
# Time  : O(n)
# Space : O(1)
class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # Use two-pointer technique - start at the extreme ends and
        # shrink the range on the side that's shorter in the hope of
        # getting a taller bar, thereby potentially getting a larger
        # area/volume
        A = height
        left, right = 0, len(A) - 1
        res = 0
        while left < right:
            res = max(res, (right - left) * min(A[right], A[left]))
            if A[left] < A[right]:
                left += 1
            else:
                right -= 1
        return res
