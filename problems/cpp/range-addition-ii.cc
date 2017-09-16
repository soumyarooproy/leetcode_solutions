// 9 ms, 09/16/2017
// Time  : O(k), k number of ops
// Space : O(1), this implementation uses O(n)
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops)
    {
        if (ops.size() == 0)
            return m * n;
        
        vector<int> rows, cols;
        for (auto x : ops) {
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }
        return min(m, *min_element(rows.begin(), rows.end())) * min(n, *min_element(cols.begin(), cols.end()));
    }
};
