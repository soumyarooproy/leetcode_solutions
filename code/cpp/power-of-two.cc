// 3 ms, 09/12/2017
// Time  : O(1), hardware latency may be ignored
// Space : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && !(n & (n - 1));
    }
};
