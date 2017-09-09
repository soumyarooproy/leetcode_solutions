// 3 ms, 09/09/2017
// Time  : O(n), n number of digits
// Space : O(1)
class Solution {
public:
    string convertToBase7(int num)
    {
        if (!num)
            return "0";
        string result;
        bool is_neg = num < 0;
        num = abs(num);
        for ( ; num; num /= 7)
            result += num % 7 + '0';
        reverse(result.begin(), result.end());
        return (is_neg? "-":"") + result;
    }
};
