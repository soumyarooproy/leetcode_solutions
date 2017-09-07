// 3ms, 09/07/2017
// Time  : O(n), worst case
// Space : O(h), worst case
int find_greater(TreeNode* root, int val)
{
    if (!root)
        return val;
    if (root->val != val)
        return root->val;
    int left_val = find_greater(root->left, val);
    int right_val = find_greater(root->right, val);

    return (left_val == val) ? right_val : (right_val == val) ? left_val : min(left_val, right_val);
}

int findSecondMinimumValue(TreeNode* root)
{
    if (!root || !root->left)
        return -1;
    int sec_min = find_greater(root, root->val);
    return (sec_min == root->val) ? -1 : sec_min;
}
