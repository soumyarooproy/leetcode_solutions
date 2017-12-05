// 6 ms, 09/09/2017
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
    int min_depth(TreeNode* root)
    {
        if (!root->left && !root->right) {
            return 1;
        }
        int min_d = numeric_limits<int>::max();
        if (root->left)
            min_d = min(min_d, min_depth(root->left));
        if (root->right)
            min_d = min(min_d, min_depth(root->right));
        return min_d + 1;
    }
    int minDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        return min_depth(root);
    }
};
