// 178 ms, 09/05/2017; 195 ms when FP adds are used
// Time  : O(n)
// Space : O(1)
double findMaxAverage(vector<int>& nums, int k)
{
    int sum = accumulate(nums.begin(), nums.begin() + k, 0), max_sum = sum;
    for (int i = 0, n = nums.size(); i + k < n; ++i) {
        sum += nums[i + k] - nums[i];
        max_sum = max(max_sum, sum);
    }
    return static_cast<double>(max_sum) / k;
}
