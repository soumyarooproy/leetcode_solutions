// 3 ms, 09/10/2017
// Time  : O(n)
// Space : O(m), max number of nodes at any level
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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> rev_level_order;
        queue<TreeNode*> q;
        if (root)
            q.push(root);
        while (!q.empty()) {
            rev_level_order.push_back({});
            for (int i = 0, n = q.size(); i < n; ++i) {
                rev_level_order.back().push_back(q.front()->val);
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                q.pop();                
            }
        }
        reverse(rev_level_order.begin(), rev_level_order.end());
        return rev_level_order;
    }
};
