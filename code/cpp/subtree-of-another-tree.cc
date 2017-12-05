// 26 ms, 09/06/2017
// Time  : O(ns*nt)
// Space : O(hs)
// TODO  : Candidate nodes are the ones that have the same depth as depth(t)
// TODO  : Use serialized representions for s and t and determine if sr(t) is a substring of sr(s)
bool is_equal(TreeNode* s, TreeNode* t)
{
    if (!s && !t)
        return true;
    if (!s && t || s && !t)
        return false;
    if (s->val != t->val)
        return false;
    return is_equal(s->left, t->left) && is_equal(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t)
{
    return is_equal(s, t) || s && (isSubtree(s->left, t) || isSubtree(s->right, t));
}
