// 3 ms, 09/12/2017
// Time  : O(n^2)
// Space : O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows < 1)
            return {};
        vector<vector<int>> tr({{1}});
        tr.resize(numRows);
        for (int row = 1; row < numRows; ++row) {
            tr[row].resize(row + 1);
            tr[row].front() = tr[row].back() = 1;
            for (int col = 1; col < row; ++col)
                tr[row][col] = tr[row - 1][col - 1] + tr[row - 1][col];
        }
        return tr;
    }
};
