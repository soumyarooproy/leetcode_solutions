// 12 ms, 09/09/2017
// Time  : O(n)
// Space : O(h)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sorted_range_to_bst(const vector<int>& nums, int first, int last)
    {
        if (first > last)
            return nullptr;
        int mid = first + (last - first) / 2;
        auto root = new TreeNode(nums[mid]);
        root->left = sorted_range_to_bst(nums, first, mid - 1);
        root->right = sorted_range_to_bst(nums, mid + 1, last);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sorted_range_to_bst(nums, 0, nums.size() - 1);
    }
};
