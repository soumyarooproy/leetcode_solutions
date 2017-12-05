// 23 ms, 09/12/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int index = 0;
        return accumulate(nums.begin(), nums.end(), 0, [&index] (int sum, int num) { return sum ^ num ^ ++index; });
    }
};
