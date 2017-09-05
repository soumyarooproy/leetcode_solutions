// 16 ms, 09/05/2017
// Time  : O(n), n is the size of the tree
// Space : O(m), m is the maximum number of nodes across all the levels
// TODO  : DFS solution
vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> averages;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
        double sum = 0;
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            sum += q.front()->val;
            if (q.front()->left)
                q.emplace(q.front()->left);
            if (q.front()->right)
                q.emplace(q.front()->right);
            q.pop();
        }
        averages.emplace_back(sum / n);
    }
    return averages;
}
