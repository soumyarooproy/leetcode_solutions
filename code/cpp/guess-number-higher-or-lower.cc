// 0 ms, 09/11/2017
// Time  : O(lg n)
// Space : O(1)

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n)
    {
        int lb = 1, ub = n;
        while (lb < ub) {
            int mid = lb + (ub - lb) / 2;
            int resp = guess(mid);
            if (!resp)
                return mid;
            if (resp < 0)
                ub = mid - 1;
            else
                lb = mid + 1;
        }
        return lb;
    }
};
