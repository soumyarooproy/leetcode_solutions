// 0 ms, 09/15/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int findLUSlength(string a, string b)
    {
        return a == b ? -1 : max(a.size(), b.size());
    }
};
