// 3 ms, 09/25/2017
// Time : O(n)
// Space : O(n)
// Recursive solution
// TODO : Iterative solution - compare from the front and the back
class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        return isOneEditDistance(s, 0, t, 0, 1);
    }
private:
    bool isOneEditDistance(const string& s, int i_s, const string& t, int i_t, int num_edits)
    {
        if (!num_edits) // no remaining edits
            return s.substr(i_s) == t.substr(i_t);
        if (i_s == s.size()) // empty s
            return t.size() - i_t == num_edits;
        if (i_t == t.size()) // empty t
            return s.size() - i_s == num_edits;
        if (s[i_s] == t[i_t])
            return isOneEditDistance(s, i_s + 1, t, i_t + 1, num_edits); // unchanged s and t
        return isOneEditDistance(s, i_s + 1, t, i_t, num_edits - 1)      // insert in s
            || isOneEditDistance(s, i_s, t, i_t + 1, num_edits - 1)      // delete from s
            || isOneEditDistance(s, i_s + 1, t, i_t + 1, num_edits - 1); // replace in s
    }
};
