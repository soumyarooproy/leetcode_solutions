// 3 ms, 09/20/2017
// Time  : O(n^2)
// Space : O(n), recursion depth
// Since get_permutation_recursive() is tail-recursive, it can be easily
// implemented iteratively bringing down the space to O(1)
class Solution {
public:
    Solution()
    {
        _factorials.resize(9);
        _factorials[0] = 1;
        for (int i = 1; i < 9; ++i)
            _factorials[i] = _factorials[i - 1] * (i + 1);
    }
    string getPermutation(int n, int k)
    {
        string n_str;
        for (int i = 1; i <= n; ++i)
            n_str += i + '0';
        get_permutation_recursive(&n_str, 0, k - 1);
        return n_str;
    }
    void get_permutation_recursive(string* n_str, int index_start, int k)
    {
        string& str = *n_str;
        if (index_start == n_str->size() - 1) {
            return;
        }
        int f = _factorials[str.size() - 1 - index_start - 1];
        auto it_start = str.begin() + index_start;
        rotate(it_start, it_start + k / f, it_start + 1 + k / f);
        get_permutation_recursive(n_str, index_start + 1, k % f);
    }
private:
    vector<int> _factorials;
};
