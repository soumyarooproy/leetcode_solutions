// 3 ms, 09/12/2017
// Time  : O(m + n)
// Space : O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i_write = m + n - 1, i1_read = m - 1, i2_read = n - 1;
        for ( ; i1_read >= 0 && i2_read >= 0; --i_write)
            nums1[i_write] = (nums1[i1_read] >= nums2[i2_read]) ? nums1[i1_read--] : nums2[i2_read--];
        while (i2_read >= 0)
            nums1[i_write--] = nums2[i2_read--];
    }
};
