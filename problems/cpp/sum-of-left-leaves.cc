// 3 ms, 09/10/2017
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
    int sum_of_left_leaves(TreeNode* root, TreeNode* par)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return (root == par->left) ? root->val : 0;
        return sum_of_left_leaves(root->left, root) + sum_of_left_leaves(root->right, root);
    }
    int sumOfLeftLeaves(TreeNode* root)
    {
        return (!root) ? 0 : sum_of_left_leaves(root->left, root) + sum_of_left_leaves(root->right, root);
    }
};
