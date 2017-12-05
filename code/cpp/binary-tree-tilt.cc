// 16 ms, 09/07/2017
// Time  : O(n)
// Space : O(1)
int sum_tree(TreeNode* root, int* tilt)
{
    if (!root)
        return 0;
    int left_sum = sum_tree(root->left, tilt), right_sum = sum_tree(root->right, tilt);
    *tilt += abs(left_sum - right_sum);
    return root->val + left_sum + right_sum;
}

int findTilt(TreeNode* root)
{
    int tilt = 0;
    sum_tree(root, &tilt);
    return tilt;
}
