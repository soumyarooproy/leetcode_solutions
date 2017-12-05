// 12 ms, 09/05/2017
// Time  : O(n)
// Space : O(1)
void inorder_visit(TreeNode* root, string* str)
{
    *str += to_string(root->val);
    if (root->left || root->right) {
        *str += "(";
        if (root->left)
            inorder_visit(root->left, str);
        *str += ")";            
        if (root->right) {
            *str += "(";
            inorder_visit(root->right, str);
            *str += ")";
        }
    }
}
string tree2str(TreeNode* t)
{
    string str;
    if (!t)
        return str;
    inorder_visit(t, &str);
    return str;
}
