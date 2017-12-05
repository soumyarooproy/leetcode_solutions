// 3 ms, 09/26/2017
// Time  : O(n!) ?
// Space : O(n^2)
// EPI solution
class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        gen_paren_recur("", n, n, &result, 0);
        return result;
    }
private:
    void gen_paren_recur(const string& s, int num_left_parens, int num_right_parens, vector<string>* res, int depth)
    {
        if (!num_right_parens) {
            res->emplace_back(s);
            return;
        }
        if (num_left_parens)
            gen_paren_recur(s + '(', num_left_parens - 1, num_right_parens, res, depth + 1);
        if (num_right_parens > num_left_parens)
            gen_paren_recur(s + ')', num_left_parens, num_right_parens - 1, res, depth + 1);
    }
};
