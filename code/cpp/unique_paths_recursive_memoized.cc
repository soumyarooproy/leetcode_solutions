// 0 ms, 10/10/2017
// Time  : O(n*m)
// Space : O(m*n)
// Recursion with memoization
// TODO  : Solve using bottom-up approach
class Solution {
public:
    int uniquePaths(int m, int n, int depth = 0)
    {
        vector<vector<int>> cache(m);
        for (auto& row : cache)
            row.resize(n, 0), row.front() = 1;
        fill(cache.front().begin(), cache.front().end(), 1);
        return unique_paths_memoized(m, n, &cache);
    }
    int unique_paths_memoized(int m, int n, vector<vector<int>>* cache_ptr, int depth = 0)
    {
        auto& cache = *cache_ptr;
        if (!cache[m - 1][n - 1])
            cache[m - 1][n - 1] = unique_paths_memoized(m - 1, n, cache_ptr, depth + 1)
                                + unique_paths_memoized(m, n - 1, cache_ptr, depth + 1);
        return cache[m - 1][n - 1];
    }
};
