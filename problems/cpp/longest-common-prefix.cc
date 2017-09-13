// 6 ms, 09/12/2017
// Time  : O(n*m)
// Space : O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)
            return "";
        string& prefix = strs[0];
        int count = prefix.size();
        for (int i = 1, n = strs.size(); i < n; ++i) {
            string& str = strs[i];
            int j = 0;
            for (int ns = str.size(); j < count && j < ns && str[j] == prefix[j]; ++j);
            count = j;
        }
        return prefix.substr(0, count);
    }
};
