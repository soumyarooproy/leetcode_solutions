// TLE, 09/09/2017
// Time  : O(n^n)
// Space : O(1)
// TODO  : Recursive approach below, improve using memoization (same as Fibonacci)
class Solution {
public:
    int climbStairs(int n)
    {
        return (n < 3) ? n : climbStairs(n - 1) + climbStairs(n - 2);
    }
};
/*--------------------------------------------------------------------------*/
// 0 ms, 09/09/2017
// Time  : O(n)
// Space : O(1)
// Bottom-up
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
