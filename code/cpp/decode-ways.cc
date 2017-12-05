// 3 ms, 09/26/2017
// Time  : O(n)
// Space : O(n)
// Memoization (recursion with caching)
// TODO  : Implement bottom-up DP
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        _cache.resize(s.size(), -1);
        return num_decodings(s, 0);
    }
private:
    int num_decodings(const string& s, int start)
    {
        int n = s.size();
        if (start >= n)
            return 1;
        if (_cache[start] != -1)
            return _cache[start];
        int res = s[start] == '0' ? 0 : num_decodings(s, start + 1);
        if (start <= n - 2) {
            auto tmp = s.substr(start, 2);
            res += (tmp >= "10" && tmp <= "26") ? num_decodings(s, start + 2) : 0;
        }
        _cache[start] = res;
        return _cache[start];
    }
    vector<int> _cache;
};
