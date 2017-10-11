// 0 ms, 10/11/2017
// Time  : O(n)
// Space : O(n), can easily be O(1)
// Todo  : Top-down solution - recursion with memoization?
class Solution {
public:
    int numWays(int n, int k)
    {
        if (!n || !k)
            return 0;
        /*
          - sc[i] stores the number of ways of coloring the i-th post so that
            the (i - 1)-th post and the i-th post have the same color (sc)
          - dc[i] stores the number of ways of coloring the i-th post so that
            the (i - 1)-th post and the i-th post have different colors (dc)
          DP relation:
            sc[i] = dc[i - 1]
              - i-th post has to be colored with (i - 1)-th post's color, which
                has to be different than (i - 2)-th post's color
            dc[i] = (sc[i - 1] + dc[i - 1]) * (k - 1)
              - i-th post can be colored with anything other than (i - 1)-th post's
                color; therefore, (k - 1) options
        */
        vector<int> sc(n), dc(n);
        sc[0] = 0, sc[1] = k, dc[0] = k, dc[1] = k * (k - 1);
        for (int i = 2; i < n; ++i)
            sc[i] = dc[i - 1], dc[i] = (sc[i - 1] + dc[i - 1]) * (k - 1);
        return sc[n - 1] + dc[n - 1];
    }
};
