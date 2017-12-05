// 25 ns, 09/11/2017
// Time  : O(n^2)
// Space : O(h)
// TODO  : Try improving to O(n) by maintaining prefix/suffix sum arrays
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
private:
    int path_sum(TreeNode* root, int sum)
    {
        if (!root)
            return 0;
        sum -= root->val;
        return (!sum) + path_sum(root->left, sum) + path_sum(root->right, sum);
    }
public:
    int pathSum(TreeNode* root, int sum)
    {
        if (!root)
            return 0;
        return path_sum(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

};
