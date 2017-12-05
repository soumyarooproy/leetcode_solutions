// 3 ms, 09/29/2017
// Time  : O(n)
// Space : O(1)
// Alternative O(n) time approaches:
// (1) Have two pointers start at the ends and move towards each other (quicksort partition) 
// (2) Count the number of 0's, 1's, and 2's and then write them during a second pass (counting sort approach)
class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // Invariants:
        // |---0---|---1---|---2---|---unknown---|
        //         i1      i2      i
        for (int i1 = -1, i2 = -1, i = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] != 2) {
                swap(nums[++i2], nums[i]);
                if (nums[i2] == 0)
                    swap(nums[++i1], nums[i2]);   
            }
        }
    }
};
