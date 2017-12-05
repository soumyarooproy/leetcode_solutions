// 122 ms, 09/14/2017
// Time  : O(m * n)
// Space : O(1)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int rows = grid.size();
        int cols = rows ? grid[0].size() : 0;
        
        int perim = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                if (!grid[i][j]) continue;
                perim +=   ((i - 1 == -1)   || !grid[i - 1][j])
                         + ((j - 1 == -1)   || !grid[i][j - 1])
                         + ((i + 1 == rows) || !grid[i + 1][j])
                         + ((j + 1 == cols) || !grid[i][j + 1]);
            }
        return perim;
    }
};
