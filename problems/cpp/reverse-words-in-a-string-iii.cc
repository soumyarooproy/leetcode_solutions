// 22 ms, 09/08/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    string reverseWords(string s)
    {
        for (auto it = s.begin(), it_prev = it, end = s.end(); it_prev < end; ) {
            it = find(it_prev, end, ' ');
            if (it - it_prev > 1)
                reverse(it_prev, it);
            it_prev = it + 1; // this can go past end but will not be dereferenced
        }
        return s;
    }
};
