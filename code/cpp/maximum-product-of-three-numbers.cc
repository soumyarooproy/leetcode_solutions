// 65 ms, 09/05/2017
// Time  : O(n lg n), because of the sorting step
// Space : O(1), because the array is sorted in place, otherwise O(n)
// TODO  : Use two BSTs/Heaps, size 2 for the min values and size 3 for
//         the max values
int maximumProduct(vector<int>& nums)
{
    int n = nums.size();
    if (n < 3)
        return 0;
    sort(nums.begin(), nums.end());
    return max(nums[0] * nums[1] * nums[n - 1],
               nums[n - 3] * nums[n - 2] * nums[n - 1]);
}
