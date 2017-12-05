// 16 ms, 09/09/2017
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
    void inorder_walk(TreeNode* root, long* min_diff, long* prev)
    {
        if (!root)
            return;
        inorder_walk(root->left, min_diff, prev);
        *min_diff = min(root->val - *prev, *min_diff);
        *prev = root->val;
        inorder_walk(root->right, min_diff, prev);
    }
    int getMinimumDifference(TreeNode* root)
    {
        long prev = numeric_limits<int>::min(), min_diff = numeric_limits<int>::max();
        inorder_walk(root, &min_diff, &prev);
        return min_diff;
    }
};
