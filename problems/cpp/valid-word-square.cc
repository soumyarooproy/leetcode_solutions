// 16 ms, 09/15/2017
// Time  : O(n^2)
// Space : O(1)
class Solution {
public:
    bool validWordSquare(vector<string>& words)
    {
        int rows = words.size();
        for (int i = 0, n = words.size(); i < n; ++i)
            for (int j = 0, m = words[i].size(); j < m; ++j) {
                int m_j = words[j].size(); // number of chars in row j
                if (i != j && (j >= n && i < m_j || i >= m_j && j < n || i < m_j && j < n && words[i][j] != words[j][i]))
                    return false;
            }
        return true;
    }
};
