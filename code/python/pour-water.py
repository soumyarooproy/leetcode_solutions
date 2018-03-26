# Date  : 03/26/2018
# Time  : O(V*n)
# Space : O(1)

class Solution:
    def pourWater(self, heights, V, K):
        """
        :type heights: List[int]
        :type V: int
        :type K: int
        :rtype: List[int]
        """

        for _ in range(V):
            i = K
            while i > 0 and heights[i - 1] <= heights[i]:
                i -= 1
            while i < K and heights[i] == heights[i + 1]:
                i += 1
            if i == K:
                while i < len(heights) - 1 and heights[i] >= heights[i + 1]:
                    i += 1
                while i > K and heights[i] == heights[i - 1]:
                    i -= 1
            heights[i] += 1

        return heights
