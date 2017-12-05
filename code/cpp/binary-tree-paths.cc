// 6 ms, 09/04/2017
// TODO: For speed-up, drop recursion and implement DFS using a stack
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
    string path_to_str(const vector<int>& path) const
    {
        if (path.size() == 0)
            return "";
        string str;
        str += to_string(path[0]);
        for (int i = 1, n = path.size(); i < n; ++i) {
            str += "->" + to_string(path[i]);
        }
        return str;
    }
    
    void binary_tree_paths(TreeNode* root, vector<int>* curr_path, vector<string>* all_paths)
    {
        if (!root->left && !root->right) {
            curr_path->emplace_back(root->val);
            all_paths->emplace_back(move(path_to_str(*curr_path)));
            curr_path->pop_back();
            return;
        }
        
        curr_path->emplace_back(root->val);
        if (root->left)
            binary_tree_paths(root->left, curr_path, all_paths);
        if (root->right)
            binary_tree_paths(root->right, curr_path, all_paths);
        curr_path->pop_back();
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        if (!root)
            return {};
        vector<string> all_paths;
        vector<int> curr_path;
        binary_tree_paths(root, &curr_path, &all_paths);
        return all_paths;
    }
};
