// 3 ms, 09/12/2017
// Time  : O(lg n)
// Space : O(lg n), can be O(1) when implemented iteratively
class Solution {
public:
    bool isPowerOfFour(int num)
    {
        if (num < 4)
            return num == 1;
        return !(num % 4) && isPowerOfFour(num/4);
    }
};
/*-----------------------------------------------------------------*/
// Use cmath functions
class Solution {
public:
    bool isPowerOfFour(int num)
    {
        return num == 1 || num >= 4 && pow(4, floor(log2(num) / 2)) == num;
    }
};
