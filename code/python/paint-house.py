# Date  : 03/17/2018
# Time  : O(m*n), m = number of colors (3), n = number of houses
# Space : O(m*n)

class Solution:
    def minCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if not costs:
            return 0

        for h in range(1, len(costs)):
            costs[h][0] += min(costs[h-1][1], costs[h-1][2])
            costs[h][1] += min(costs[h-1][0], costs[h-1][2])
            costs[h][2] += min(costs[h-1][0], costs[h-1][1])

        return min(costs[-1])
