// 12 ms, 09/19/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        auto it = is_sorted_until(nums.rbegin(), nums.rend());
        if (it != nums.rend()) {
            auto it_just_greater = upper_bound(nums.rbegin(), it, *it);
            iter_swap(it, it_just_greater);
        }
        reverse(nums.rbegin(), it);
    }
};
