// 9 ms, 09/28/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int sum = 0, min_len = numeric_limits<int>::max();
        for (int i = 0, j = -1, n = nums.size(); i < n && j < n; ) {
            if (sum < s) {
                sum += nums[++j];
            } else { // sum >= s
                min_len = min(min_len, j - i + 1);
                sum -= nums[i++];
            }
        }
        return min_len == numeric_limits<int>::max() ? 0 : min_len;
    }
};
