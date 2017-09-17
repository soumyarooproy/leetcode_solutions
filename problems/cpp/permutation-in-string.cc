// 9 ms, 09/17/2017
// Time  : O(m * n)
// Space : O(m)
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size(), n = s2.size();
        
        if (m > n)
            return false;
        
        // Convert s1 to a char to frequency map
        array<int, 26> map_s1;
        map_s1.fill(0);
        for (auto c : s1)
            ++map_s1[c - 'a'];
        
        // Use a sliding char to frequency map in s2 to determine matches
        array<int, 26> map_s2;
        map_s2.fill(0);
        int i_s2;
        for (i_s2 = 0; i_s2 < m; ++i_s2)
            ++map_s2[s2[i_s2] - 'a'];
        if (map_s2 == map_s1)
            return true;
        
        for ( ; i_s2 < n; ++i_s2) {
            --map_s2[s2[i_s2 - m] - 'a'], ++map_s2[s2[i_s2] - 'a'];
            if (map_s2 == map_s1)
                return true;
        };
        
        return false;
    }
};
