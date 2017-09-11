// 3 ms, 09/10/2017
// Time  : O(n), number of digits 
// Space : O(1)
class Solution {
public:
    int findComplement(int num)
    {
        return ((1 << static_cast<int>(floor(log2(num) + 1))) - 1) - num;
    }
};
