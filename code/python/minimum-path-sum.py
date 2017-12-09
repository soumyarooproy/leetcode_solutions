# 89 ms, 12/08/2017
# Time  : O(m*n)
# Space : O(m*n); should be optimizable to O(min(m, n))
import itertools
class Solution:
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        M = [list(itertools.accumulate(grid[0]))]
        for row in grid[1:]:
            M.append([M[-1][0] + row[0]])

        for i in range(1, len(grid)):
            for j in range(1, len(grid[0])):
                M[i].append(min(M[i][-1], M[i - 1][j]) + grid[i][j])

        return M[-1][-1]
