# 02/19/2018
# Time  : O(n + m*lgk), k=3, m is the number of distinct elems in nums
# Space : O(m + k)

class Solution:
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        s = set(nums)
        min_heap = []
        for x in s:
            heapq.heappush(min_heap, x)
            if len(min_heap) > 3:
                heapq.heappop(min_heap)
        return max(min_heap) if len(min_heap) < 3 else min_heap[0]
