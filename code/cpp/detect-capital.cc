// 9 ms, 09/09/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    bool detectCapitalUse(string word)
    {
        if (word.size() == 1)
            return true;
        enum caps {ALL_UPPER, ALL_LOWER, NEITHER};
        caps cp = isupper(word[1]) ? ALL_UPPER : ALL_LOWER;
        for (int i = 2, n = word.size(); i < n; ++i) {
            cp = (cp == ALL_UPPER && isupper(word[i]) || cp == ALL_LOWER && islower(word[i]))? cp : NEITHER;
            if (cp == NEITHER)
                return false;
        }
        return isupper(word[0]) || cp == ALL_LOWER;
    }
};
