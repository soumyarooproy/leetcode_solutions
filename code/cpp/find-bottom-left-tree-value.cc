// Traverse tree in DFS order visiting a left child before a right child
// and record the max depth. When a node with a higher depth is first
// discovered, save that element
// Time: O(n)
// Space: O(tree height), O(lg n) in a balanced binary tree

void dfs_visit(TreeNode* node, int depth, int* max_depth, int* val)
{
    ++depth;
    //cout << string(depth, ' ') << "node = " << node->val << "\n";
    if (!node->left && !node->right && *max_depth < depth) {
        *max_depth = depth;
        *val = node->val;
        return;
    }
    if (node->left)
        dfs_visit(node->left, depth, max_depth, val);
    if (node->right)
        dfs_visit(node->right, depth, max_depth, val);
}

int findBottomLeftValue_dfs(TreeNode* root)
{
    int max_depth = 0, val;
    dfs_visit(root, 0, &max_depth, &val);
    return val;
}

/*----------------------------------------------------------------------*/

// Traverse tree in level-order traversal and at each new level, save the
// first element
// Time: O(n)
// Space: O(max nodes at any level), O(n) in a balanced binary tree

int findBottomLeftValue_levelorder(TreeNode* root)
{
    int result;
    queue<TreeNode*> q;
    q.push(root);

    // Traverse the tree in level order
    while (!q.empty()) {
        auto num_nodes = q.size();
        result = q.front()->val;
        // Add the next level ndoes to the queue; left child before right child
        for (int i = 0; i < num_nodes; ++i) {
            auto node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
    return result;
}
