// 26 ms, 09/18/2017
// Time  : O(h)
// Space : O(h)
// TODO  : Solve it iteratively
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) { return inorder_successor(root, p, nullptr); }
private:
    TreeNode* inorder_successor(TreeNode* root, TreeNode* p, TreeNode* succ_so_far)
    {
        if (root == p)
            return root->right? leftmost_node(root->right, depth) : succ_so_far;
        if (p->val < root->val)
            return inorder_successor(root->left, p, root);
        // if (p->val > root->val)
        return inorder_successor(root->right, p, succ_so_far);
    }
    TreeNode* leftmost_node(TreeNode* root, int depth) { return root->left ? leftmost_node(root->left) : root; }
};
