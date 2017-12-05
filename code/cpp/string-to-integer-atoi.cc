// 15 ms, 09/26/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int myAtoi(string str)
    {
        int n = str.size();
        
        // Skip leading whitespaces
        int index = 0;
        for ( ; isspace(str[index]); ++index);

        // Determine -ve/+ve
        bool neg = str[index] == '-';
        if (str[index] == '-' || str[index] == '+')
            ++index;
        
        // Compute the integer
        long result = 0;
        for (int n_max = min(n, index + 11); index < n_max && isdigit(str[index]); ++index)
            result *= 10, result += str[index] - '0';
        if (neg)
            result = -result;
        
        // Remaining overflow/underflor
        if (result < numeric_limits<int>::min())
            return numeric_limits<int>::min();
        if (result > numeric_limits<int>::max())
            return numeric_limits<int>::max();
        
        return result;
    }
};
