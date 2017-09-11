// 3 ms, 09/10/2017
// Time  : O(n) + O(m) = O(n)
// Space : O(m), number of distinct characters
class Solution {
public:
    int longestPalindrome(string s)
    {
        array<int, 128> char_freq;
        char_freq.fill(0);
        for (auto c : s)
            ++char_freq[c];
        auto count = 0;
        bool singlet = false;
        for (auto i : char_freq) {
            count += i / 2;
            singlet |= (i % 2 == 1);
        }
        return 2 * count + singlet;
    }
};
