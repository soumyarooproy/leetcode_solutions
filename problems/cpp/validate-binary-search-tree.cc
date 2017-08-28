/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool is_valid_bst(TreeNode* root, long min_key, long max_key)
{
    if (!root)
        return true;

    return root->val > min_key && root->val < max_key
           && is_valid_bst(root->left, min_key, root->val)
           && is_valid_bst(root->right, root->val, max_key);
}

bool isValidBST(TreeNode* root)
{
    // Need to use long here because of a few testcases with -2**31 and (2**31 - 1)
    // valued keys
    return is_valid_bst(root, numeric_limits<long>::min(), numeric_limits<long>::max());
}
