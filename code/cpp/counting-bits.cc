// 66 ms, 10/12/2017
// Time  : O(n)
// Space : O(1), output size is not auxiliary space
class Solution {
public:
    vector<int> countBits(int num)
    {
        vector<int> result(num + 1);
        for (int i = 1; i <= num; ++i)
            result[i] = result[i >> 1] + (i & 0x1); // or result[i] = 1 + result[i & (i - 1)];
        return result;
    }
};
