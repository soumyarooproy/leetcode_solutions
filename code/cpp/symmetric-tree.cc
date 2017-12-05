// 3 ms, 09/09/2017
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
    bool is_mirror(TreeNode* root1, TreeNode* root2)
    {
        return !root1 && !root2
               || root1 && root2
                  && root1->val == root2->val
                  && is_mirror(root1->left, root2->right)
                  && is_mirror(root2->left, root1->right);
    }
    bool isSymmetric(TreeNode* root)
    {
        return !root || is_mirror(root->left, root->right);
    }
};
