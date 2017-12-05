// 12 ms, 09/25/2017
// Time  : O(n^2)
// Space : O(n)
// TODO  : No early termination; see better solution below
class Solution {
public:
    int countSubstrings(string s)
    {
        int n = s.size(), count = n;
        
        vector<vector<bool>> p(2);
        p[0].resize(n, true), p[1].resize(n - 1, false);

        for (int i = 0; i < n - 1; ++i)
            if (s[i] == s[i + 1])
                p[1][i] = true, ++count;
        
        for (int len = 2; len <= n; ++len)
            for (int i = 0; i < n - len; ++i) {
                auto& prev = p[len % 2];
                if (prev[i] = prev[i + 1] && s[i] == s[i + len])
                    ++count;
            }

        return count;
    }
};
/*----------------------------------------------------------------------------------*/
// Cleaner (6 ms) solution on leetcode
class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0;i<s.size();i++) {
            // Odd length palindromes centered at i
            for(int j=0; i-j>=0 && i+j<s.size() && s[i-j]==s[i+j]; j++) res++;
            // Even length palindromes centered at (i-1,i)
            for(int j=0; i-j-1>=0 && i+j<s.size() && s[i-j-1]==s[i+j]; j++) res++;
        }
        return res;
    }
