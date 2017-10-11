// TLE, 10/10/2017
// Time  : O(n^n)
// Space : O(1)
// Too slow; memoize it
class Solution {
public:
    int uniquePaths(int m, int n) {
        return (!(m - 1) || !(n - 1)) ? 1 : uniquePaths(m, n - 1) + uniquePaths(m - 1, n);
    }
};
