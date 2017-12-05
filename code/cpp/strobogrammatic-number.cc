// 0 ms, 09/16/2017
// Time  : O(n)
// Space : O(1)
// TODO  : Use a lookup table - 0->0, 6->9, 8->8, etc.
class Solution {
public:
    bool isStrobogrammatic(string num)
    {
        int n = num.size(), mid = n / 2;
        for (int i = 0, j = n - 1; i <= mid; ++i, --j) {
            if ((num[i] == num[j] && (num[i] == '0' || num[i] == '1' || num[i] == '8'))
                || num[i] == '6' && num[j] == '9' || num[i] == '9' && num[j] == '6')
                continue;
            return false;
        }
        return true;
    }
};
