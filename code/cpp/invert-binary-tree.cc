// 0 ms, 09/04/2017
// Time  : O(n)
// Space : O(h)
TreeNode* invertTree(TreeNode* root)
{
    if (root) {
        auto temp(invertTree(root->left));
        root->left = invertTree(root->right);
        root->right = temp;
    }
    return root;
}
