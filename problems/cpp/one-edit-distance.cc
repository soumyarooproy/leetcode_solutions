// 3 ms, 09/25/2017
// Time : O(n)
// Space : O(n)
// Recursive solution
// TODO : Simplify this
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
/*-------------------------------------------------------------------------*/
// Iterative solution
// TODO : Simplify this
class Solution {
public:
    bool isOneEditDistance(string s, string t)
    {
        // Compare left-to-right
        auto it = mismatch(s.cbegin(), s.cend(), t.cbegin());
        if (it.first == s.cend())
            return t.cend() - it.second == 1;
        if (it.second == t.cend())
            return s.cend() - it.first == 1;
        
        // Compare right-to-left
        auto rit = mismatch(s.crbegin(), s.crend(), t.crbegin());
        if (rit.first == s.crend())
            return t.crend() - rit.second == 1;
        if (rit.second == t.crend())
            return s.crend() - rit.first == 1;
        
        int i_s = it.first - s.cbegin();
        int i_t = it.second - t.cbegin();
        int ri_s = s.crend() - rit.first - 1;
        int ri_t = t.crend() - rit.second - 1;

        return ri_s == i_s && ri_t == i_t        // replace in s or t
            || ri_s == (i_s - 1) && ri_t == i_t  // insert in s or delete from t
            || ri_s == i_s && ri_t == (i_t - 1); // delete from s or insert in t
    }
};
