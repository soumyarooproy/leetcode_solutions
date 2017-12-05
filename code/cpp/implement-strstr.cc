// 6 ms, 09/13/2017
// Time  : O(n*m)
// Space : O(m) for this implementation; can easily be O(1)
// TODO  : Implement KMP, BM/BMH, or KR
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        for (int i = 0, n = haystack.size(), m = needle.size(); i <= n - m; ++i)
            if (haystack.substr(i, m) == needle)
                return i;
        return -1;
    }
};
