// 0 ms, 09/12/2017
// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        deque<vector<int>> row_pascal({{1}});
        for (int i = 0; i <= rowIndex; ++i) {
            row_pascal.push_back({});
            row_pascal.back().resize(i + 1);
            row_pascal.back().front() = row_pascal.back().back() = 1;
            for (int j = 1; j < i; ++j)
                row_pascal[1][j] = row_pascal[0][j - 1] + row_pascal[0][j];
            row_pascal.pop_front();
        }
        return row_pascal.back();
    }
};
/*--------------------------------------------------------------------------*/
// In the same space as the output
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row (rowIndex + 1);
        
        // If rowIndex is 0, return [1]
        if (rowIndex == 0) {
            return vector<int>({1});
        }
        
        // If rowIndex is 1, return [1, 1]
        if (rowIndex == 1) {
            return vector<int>({1, 1});
        }
        
        // For rowIndex 2 or greater, initialize
        // row to [1, 1]
        row[0] = row[1] = 1;
        
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) {
                row[j] = row[j-1] + row[j];
            }
            row[0] = row[i] = 1;
        }
        
        return row;
    }
};
