// 13 ns, 09/15/2017
// Time  : O(n)
// Space : O(1)
// TODO  : Look up EPI solution; also do not use is_sorted_until()
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int max_len = 0;
        for (auto it = nums.begin(), end = nums.end(), it_end = it; it != end; it = it_end) {
            it_end = is_sorted_until(it, end, std::less_equal<int>());
            max_len = max(max_len, static_cast<int>(it_end - it));
        }
        return max_len;
    }
};
