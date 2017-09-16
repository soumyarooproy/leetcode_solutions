// 0 ms, 09/15/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s)
    {
        vector<string> res;
        int n = s.size();
        for (int pos = 0; pos != string::npos; ) {
            if ((pos = s.find("++", pos)) != string::npos) {
                res.emplace_back(s);
                res.back()[pos] = '-';
                res.back()[++pos] = '-';
            }
        }
        return res;
    }
};
