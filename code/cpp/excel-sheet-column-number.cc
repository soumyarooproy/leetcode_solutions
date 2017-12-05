// 3 ms, 09/11/2017
// Time  : O(n), size of string
// Space : O(1)
class Solution {
public:
    int titleToNumber(string s)
    {
        int num = 0;
        for (auto c : s)
            num = 26 * num + c - 'A' + 1;
        return num;
    }
};
