// 9 ms, 09/09/2017
// Time  : O(n)
// Space : O(h)
// TODO  : Return a struct/pair instead of bool
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
    bool is_balanced(TreeNode* root, int* height)
    {
        if (!root) {
            *height = 0;
            return true;
        }
        int height_left, height_right;
        if (!is_balanced(root->left, &height_left))
            return false;
        if (!is_balanced(root->right, &height_right))
            return false;
        *height = max(height_left, height_right) + 1;
        return abs(height_right - height_left) <= 1;
    }

    bool isBalanced(TreeNode* root)
    {
        int height;
        return is_balanced(root, &height);
    }
};
/*--------------------------------------------------------*/
// Return height and balanced info by value
class Solution {
private:
    struct tree_info { bool is_balanced; int height; };
    tree_info get_tree_info(TreeNode* root)
    {
        if (!root)
            return {true, 0};
        auto left_tree_info = get_tree_info(root->left);
        if (!left_tree_info.is_balanced)
            return {false, 0};
        auto right_tree_info = get_tree_info(root->right);
        if (!right_tree_info.is_balanced)
            return {false, 0};
        return {abs(left_tree_info.height - right_tree_info.height) <= 1,
                max(left_tree_info.height, right_tree_info.height) + 1};
    }
public:
    bool isBalanced(TreeNode* root)
    {
        return get_tree_info(root).is_balanced;
    }
};
