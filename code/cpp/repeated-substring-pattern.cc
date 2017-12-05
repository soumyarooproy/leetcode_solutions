// 29 ms, 09/12/2017
// Time  : O(n^2)
// Space : O(n) in this implementation, but could easily be O(1)
// TODO  : DP approach below
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
/*--------------------------------------------------------*/
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n+1,0);
        while( i < str.size() ){
            if( str[i] == str[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
    }
};
