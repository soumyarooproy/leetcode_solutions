// 102 ms, 09/28/2017
// Time  : O(md lg d + ndm), d - size of the dictionary, m - size of dictionary words, n - size of the query string
// Space : O(1)
// Sort the dictionary by length for early termination
class Solution {
public:
    string findLongestWord(string s, vector<string>& d)
    {
        sort(d.begin(), d.end(),
             [] (const string& x, const string& y) { return x.size() == y.size() ? x < y : x.size() > y.size(); });
        
        int m = s.size();
        for (auto& x : d) {
            if (x.size() > m)
                break;
            if (is_subsequence(s, x))
                return x;
        }
        return "";
    }
private:
    bool is_subsequence(const string& s_query, const string& s_match)
    {
        int i_q = 0, i_m = 0, len_m = s_match.size();
        for (int len_q = s_query.size(); i_q < len_q && i_m < len_m; ++i_q)
            if (s_query[i_q] == s_match[i_m])
                ++i_m;
        return i_m == len_m;
    }
};
/*-----------------------------------------------------------------*/
// Time  : O(ndm), d - size of the dictionary, m - size of dictionary words, n - size of the query string
// No sorting
class Solution {
public:
    string findLongestWord(string s, vector<string>& d)
    {
        int i_max = -1;
        int m = s.size();
        for (int n = d.size(), i = 0; i < n; ++i) {
            const string& x = d[i];
            if (x.size() <= m && is_subsequence(s, x))
                i_max = (i_max == -1 || (d[i_max].size() < x.size() || d[i_max].size() == x.size() && x < d[i_max])) ? i : i_max;
        }
        return i_max == -1 ? "" : d[i_max];
    }
private:
    bool is_subsequence(const string& s_query, const string& s_match)
    {
        int i_q = 0, i_m = 0, len_m = s_match.size();
        for (int len_q = s_query.size(); i_q < len_q && i_m < len_m; ++i_q)
            if (s_query[i_q] == s_match[i_m])
                ++i_m;
        return i_m == len_m;
    }
};
