// 3 ms, 09/11/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    string addStrings(string num1, string num2)
    {
        string result;
        // Implement a ripple-carry adder
        int carry = 0;
        for (int n1 = num1.size(), n2 = num2.size(), i1 = n1 - 1, i2 = n2 - 1; i1 >= 0 || i2 >= 0; --i1, --i2) {
            int sum = carry;
            if (i1 >= 0)
                sum += num1[i1] - '0';
            if (i2 >= 0)
                sum += num2[i2] - '0';
            result += sum % 10 + '0';
            carry = sum / 10;
        }
        if (carry)
            result += '1';
        reverse(result.begin(), result.end());
        return result;
    }
};
