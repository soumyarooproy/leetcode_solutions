// 0 ms, 09/11/2017
// Time  : O(n)
// Space : O(m), number of distinct characters
class Solution {
public:
    bool canPermutePalindrome(string s)
    {
        array<int, 128> char_freq;
        char_freq.fill(0);
        int num_odd = 0;
        for (auto c : s)
            if (++char_freq[c] & 0x1)
                ++num_odd;
            else
                --num_odd;
        return num_odd < 2;
    }
};
