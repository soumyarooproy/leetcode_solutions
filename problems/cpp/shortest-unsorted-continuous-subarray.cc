// 76 ms, 09/01/2017
int findUnsortedSubarray(vector<int>& nums)
{
    // Find the sorted ranges at the beginning and at the end
    auto it1 = is_sorted_until(nums.cbegin(), nums.cend());

    if (it1 == nums.cend())
        return 0;

    auto rit2 = is_sorted_until(nums.crbegin(), nums.crend(), greater<int>());
    auto it2 = nums.cbegin() + (nums.crend() - rit2) + 1;       

    // Find the min and max of the unsorted range [i1, it2)
    auto minmax = minmax_element(it1 - 1, it2);

    it1 = upper_bound(nums.cbegin(), it1, *minmax.first);
    it2 = lower_bound(it2, nums.cend(), *minmax.second);

    return it2 - it1;
}
/*---------------------------------------------------------------------------------*/
// TODO: faster solution (33 ms) on leetcode
// Same algorithm as above but no standard library calls
int findUnsortedSubarray(vector<int>& nums) {
    int begin = 0, end = nums.size() - 1, res = 0;

    while (begin < nums.size() - 1 && nums[begin] <= nums[begin + 1]) begin++;
    while (end > 0 && nums[end] >= nums[end - 1]) end--;

    if (end > begin) {
        int min = INT_MAX, max = INT_MIN;
        for (int i = begin; i <= end; i++) {
            if (nums[i] < min) {
                min = nums[i];
            }
            if (nums[i] > max) {
                max = nums[i];
            }
        }

        while (begin >= 0 && nums[begin] > min) begin--;
        while (end < nums.size() && nums[end] < max) end++;

        res =  end - begin - 1;
    }
    return res;
}
