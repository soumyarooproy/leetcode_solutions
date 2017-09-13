// 9 ms, 09/12/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if (!nums.size())
            return 0;
        int max_sum = nums[0];
        for (int i = 0, n = nums.size(), sum = 0; i < n; ++i) {
            sum += nums[i];
            max_sum = max(max_sum, sum);
            if (sum < 0)
                sum = 0;
        }
        return max_sum;
    }
};
