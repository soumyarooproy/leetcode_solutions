// 42 ms, 09/05/2017
// Time  : O(n), where 'n' is the size of the overlapping/common subtree
// Space : O(h), where 'h' is the height of the overlapping/common subtree
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
{
    if (!t1)
        return t2;
    if (!t2)
        return t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);
    return t1;
}
