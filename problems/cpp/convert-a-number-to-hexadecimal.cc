// 3 ms, 09/10/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    string toHex(int num)
    {
        if (!num)
            return "0";
        string hex_digits("0123456789abcdef"), hex;
        for (int i = 0; num && i < 8; ++i) {
            hex += hex_digits[num & 0xf];
            num >>= 4;            
        }
        reverse(hex.begin(), hex.end());
        return hex;
    }
};
