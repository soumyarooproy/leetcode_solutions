// 36 ms, 09/05/2017
// Time  : O(n), 2 passes over the elements, once in the tree, the other in
//         the auxilliary sorted vector
// Space : O(n), for the auxilliary sorted vector; inorder traversal takes
//         O(h) space; O(1) space if the BST is transformed into a
//         doubly-linked list
// TODO  : Work directly on the BST
bool two_sum(const vector<int>& v, int sum)
{
    int left_i = 0, right_i = v.size() - 1;
    while (left_i < right_i) {
        auto temp_sum = v[left_i] + v[right_i];
        if (temp_sum == sum)
            return true;
        if (temp_sum > sum)
            --right_i;
        else
            ++left_i;
    }
    return false;
}
void bst_inorder(TreeNode* root, vector<int>* sorted)
{
    if (!root)
        return;
    bst_inorder(root->left, sorted);
    sorted->emplace_back(root->val);
    bst_inorder(root->right, sorted);
}
bool findTarget(TreeNode* root, int k)
{
    vector<int> sorted;
    bst_inorder(root, &sorted);
    return two_sum(sorted, k);
}
