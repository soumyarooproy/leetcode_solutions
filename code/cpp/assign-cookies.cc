// 39 ms, 09/11/2017
// Time  : O(n lg n)
// Space : O(1)
// TODO  : Use heaps
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i_g = 0, i_s = 0;
        for (int n_g = g.size(), n_s = s.size() ; i_g < n_g && i_s < n_s; ++i_s)
            if (g[i_g] <= s[i_s])
                ++i_g;
        return i_g;
    }
};
