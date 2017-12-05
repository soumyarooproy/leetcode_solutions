// 53 ms, 09/12/2017
// Time  : O(1)
// Space : O(1)
class Solution {
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && pow(3, floor(log2(n) / log2(3))) == n;
    }
};
