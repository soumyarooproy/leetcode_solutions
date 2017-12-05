// 15 ms, 09/11/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        
        for (int i_z = 0, i_n = 0, n = nums.size(); i_z < n && i_n < n; ) {
            while (i_z < n && nums[i_z] != 0) ++i_z;
            while (i_n < n && nums[i_n] == 0) ++i_n;
            if (i_z < n && i_n < n && i_z < i_n)
                swap(nums[i_z++], nums[i_n]);
            ++i_n;
        }
    }
};
/*---------------------------------------------------*/
// TODO  : Cleaner solution on leetcode
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[idx++], nums[i]);
            }
        }
        return;
    }
};
