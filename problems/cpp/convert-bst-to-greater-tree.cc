// 35 ms, 09/08/2017
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
    void convert_to_greater(TreeNode* root, int* sum)
    {
        if (!root)
            return;
        convert_to_greater(root->right, sum);
        int sum_greater = *sum;
        root->val += *sum;
        *sum = root->val;
        convert_to_greater(root->left, sum);
    }
    TreeNode* convertBST(TreeNode* root)
    {
        int sum = 0;
        convert_to_greater(root, &sum);
        return root;
    }
};
