// 49 ms, 09/15/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums)
    {
        int sum = 0, min = nums[0];
        for (auto x : nums) {
            sum += x;
            min = std::min(min, x);
        }
        return sum - min * nums.size();
    }
};
