// 0 ms, 09/10/2017
// Time  : O(n)
// Space : O(n)
// Note  : Recursive
class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b,(a & b) << 1);
    }
};
/*------------------------------------------------------------------*/
// 0 ms, 09/10/2017
// Time  : O(n)
// Space : O(1)
// Note  : Iterative
class Solution {
public:
    int getSum(int a, int b)
    {
        // Model this as a ripple-carry-adder
        // Use bitwise operators
        int i = 0, carry = 0, sum = 0;
        for ( ; i < 32; ++i) {
            int bit_a = a & 0x1, bit_b = b & 0x1;
            sum |= (bit_a ^ bit_b ^ carry) << i;
            carry = bit_a & bit_b | bit_b & carry | bit_a & carry;
            a >>= 1;
            b >>= 1;
        }
        if (carry)
            sum |= (1 << i);
        return sum;
    }
};
