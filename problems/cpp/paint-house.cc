// 3 ms, 09/15/2017
// Time  : O(n * k), k = 3
// Space : O(n * k), k = 3
class Solution {
public:
    int minCost(vector<vector<int>>& costs)
    {
        int n = costs.size();
        if (n == 0)
            return 0;
        for (int i = 1; i < n; i++) {
            costs[i][0] += min(costs[i - 1][1],costs[i - 1][2]);
            costs[i][1] += min(costs[i - 1][0],costs[i - 1][2]);
            costs[i][2] += min(costs[i - 1][0],costs[i - 1][1]);
        }
        return *min_element(costs[n-1].begin(), costs[n-1].end());
    }
};
