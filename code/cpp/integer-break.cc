// 0 ms, 09/17/2017
// Time  : O(n^2)
// Space : O(n)
class Solution {
public:
    int integerBreak(int n)
    {
        if (n < 4) // n = 2, n = 3
            return n - 1;
        
        _max_break.reserve(n + 1);
        _max_break.resize(2);
        _max_break[1] = 1;
        for (int i = 2; i <= n; ++i) {
            int max = i;
            for (int j = 1; j <= i / 2; ++j)
                max = std::max(max, _max_break[j] * _max_break[i - j]);
            _max_break.push_back(max);
        }
        return _max_break.back();
    }
private:
    vector<int> _max_break;
};
