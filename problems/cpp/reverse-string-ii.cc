// 6 ms, 09/08/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    string reverseStr(string s, int k) {
        if (k < 1) return s;
        auto it = s.begin(), end = s.end();
        for ( ; it < end; it += 2*k) {
            reverse(it, min(it + k, end));
        }
        return s;
    }
};
