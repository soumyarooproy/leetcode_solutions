// TLE, 09/09/2017
// Time  : O(n^n)
// Space : O(1)
// Note  : Same as Fibonacci
class Solution {
public:
    int climbStairs(int n)
    {
        return (n == 1) ? 1 : (n == 2) ? 2 : climbStairs(n - 1) + climbStairs(n - 2);
    }
};
/*--------------------------------------------------------------------------*/
// 0 ms, 09/09/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int climbStairs(int n)
    {
        if (n < 2)
            return 1;
        int c1 = 1, c2 = 2;
        for (int i = 3; i <= n; ++i) {
            int c = c1 + c2;
            c1 = c2;
            c2 = c;
        }
        return c2;
    }
};
