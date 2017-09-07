// 36 ms, 09/07/2017
// Time  : O(n)
// Space : O(1)
// TODO  : Skip 0's and count 1's in separate loops to improve branch prediction?
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int num_1s = 0, max_1s = 0;
        for (int i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i])
                ++num_1s;
            else if (num_1s) {
                max_1s = max(max_1s, num_1s);
                num_1s = 0;
            }
        }
        return max(max_1s, num_1s);;
    }
};
