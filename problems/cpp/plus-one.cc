// 3 ms, 09/09/2017
// Time  :
// Space :
class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int carry = 1;
        for (int n = digits.size(), i = n - 1; i >= 0; --i) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
