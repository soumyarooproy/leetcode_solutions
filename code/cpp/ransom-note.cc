// 22 ms, 09/10/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        array<int, 26> char_freq;
        char_freq.fill(0);
        for (auto c : magazine)
            ++char_freq[c - 'a'];
        for (auto c : ransomNote)
            if (!char_freq[c - 'a']--)
                return false;
        return true;
    }
};
