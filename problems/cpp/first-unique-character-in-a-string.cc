// 39 ms, 09/15/2017
// Time  : O(n)
// Space : O(k), k is 26 in this case
class Solution {
public:
    int firstUniqChar(string s)
    {
        array<int, 26> map;
        int n = s.size();
        map.fill(n);
        for (int i = 0; i < n; ++i) {
            auto j = s[i] - 'a';
            if (map[j] == n) // char seen first time
                map[j] = i;
            else if (map[j] != n + 1) // char seen multiple times
                map[j] = n + 1;
        }
        int min_val = *min_element(map.begin(), map.end());
        return min_val < n ? min_val : -1; 
    }
};
