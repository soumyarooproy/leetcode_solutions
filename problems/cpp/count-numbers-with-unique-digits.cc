class Solution {
public:
    int countNumbersWithUniqueDigits(int n)
    {
        /*
        For n digits, 1 < n <= 10:
          9 options for Most Significant Digit (MSD), cannot be '0'
          9 options for MS-1st Digit, can be '0'
          8 options for MS-2nd Digit, can be '0'
          7 options for MS-3rd Digit, can be '0'
          ... etc.
          if n > 10, 0 options
          if n == 1, 10 options ([0, 9])
        */
        if (n > 10)
            return 0;
        if (!n)
            return 1;
        int sum = 10, prod = 9;
        for (int i = 2; i <= n; ++i)
            prod *= (11 - i), sum += prod;
        return sum;
    }
};
