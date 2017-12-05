// 6 ms, 09/08/2017
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
    int depth(TreeNode* root, int* diameter)
    {
        if (!root) {
            return -1;
        }
        int depth_left_subtree = depth(root->left, diameter);
        int depth_right_subtree = depth(root->right, diameter);
        *diameter = max(*diameter, 2 + depth_left_subtree + depth_right_subtree);
        return 1 + max(depth_left_subtree, depth_right_subtree);
    }
    
    int diameterOfBinaryTree(TreeNode* root)
    {
        int diameter = 0;
        depth(root, &diameter);
        return diameter;
    }
};
