// 16 ms, 09/09/2017
// Time  : O(n)
// Space : O(m), number of distinct keys
// TODO  : Write into the output vector directly
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
    void inorder_traversal(TreeNode* root, unordered_map<int, int>* elem_freq)
    {
        if (!root)
            return;
        inorder_traversal(root->left, elem_freq);
        ++(*elem_freq)[root->val];
        inorder_traversal(root->right, elem_freq);
    }
    
    vector<int> findMode(TreeNode* root)
    {
        if (!root)
            return {};
        
        unordered_map<int, int> elem2freq;
        inorder_traversal(root, &elem2freq);
        
        map<int, vector<int>> freq2elem;
        for (auto& x : elem2freq)
            freq2elem[x.second].push_back(x.first);

        return freq2elem.crbegin()->second;
    }
};
