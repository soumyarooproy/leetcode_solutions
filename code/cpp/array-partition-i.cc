// 85 ms, 09/06/2017
// Time  : O(n lg n) for comparison sort; or O(n) for non-comparison sort 
// Space : O(1) for in-place sort; or O(k) for non-comparison sort, where k is the range of values in nums
// TODO  : Use hashmap of value->freq pairs; see solution on leetcode
int arrayPairSum(vector<int>& nums)
{
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0, n = nums.size() ; i < n; i += 2)
        sum += nums[i];
    return sum;
}
