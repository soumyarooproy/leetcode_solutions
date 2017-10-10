// 3 ms, 10/09/2017
// Time  : O(n)
// Space : O(n)
// TODO  : Solve it with O(1) space
class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        if (nums.size() < 2)
            return nums.empty() ? 0 : nums[0];

        /*
           Compute the max subarray product ending at index i using
           the DP relation:
             prod_pos[i] = nums[i] * max(1, prod_pos[i - 1]) if nums[i] > 0 else nums[i] * prod_neg[i - 1]
             prod_neg[i] = nums[i] * max(1, prod_pos[i - 1]) if nums[i] < 0 else nums[i] * prod_neg[i - 1]
           where,
             prod_pos[i] is the max magnitude +ve value prod of subarray with i as the last element, and
             prod_neg[i] is the max magnitude -ve value prod of subarray with i as the last element
        */

        vector<int> prod_pos(nums.size()), prod_neg(nums.size());
        if (nums[0] > 0)
            prod_pos[0] = nums[0], prod_neg[0] = 0;
        else
            prod_neg[0] = nums[0], prod_pos[0] = 0;
        
        int max_prod = prod_pos[0];
        for (int i = 1, n = nums.size(); i < n; ++i) {
            prod_pos[i] = nums[i] > 0 ? nums[i] * max(1, prod_pos[i - 1]) : nums[i] * prod_neg[i - 1];
            prod_neg[i] = nums[i] < 0 ? nums[i] * max(1, prod_pos[i - 1]) : nums[i] * prod_neg[i - 1];
            max_prod = max(max_prod, prod_pos[i]);
        }
        return max_prod;
    }
};
