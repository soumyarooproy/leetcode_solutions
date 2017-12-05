// 6 ms, 09/10/2017
// Time  : O(h)
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
    int closestValue(TreeNode* root, double target)
    {
        if (root && !root->left && !root->right)
           return root->val;
        double closest_val = numeric_limits<double>::max(); // is this right?
        if (target > root->val && root->right)
            closest_val = closestValue(root->right, target);
        else if (target < root->val && root->left)
            closest_val = closestValue(root->left, target);
        return abs(target - root->val) < abs(target - closest_val) ? root->val : closest_val;
    }
};
