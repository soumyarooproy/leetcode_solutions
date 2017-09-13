// 29 ms, 09/12/2017
// Time  : O(n^2)
// Space : O(n) in this implementation, but could easily be O(1)
class Solution {
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        for (int i = n/2; i ; --i) {
            if (n % i)
                continue;
            auto substr = s.substr(0, i);
            int j;
            for (j = 0; j < n; j += i)
                if (substr != s.substr(j, i))
                    break;
            if (j >= n)
                return true;
        }
        return false;
    }
};
