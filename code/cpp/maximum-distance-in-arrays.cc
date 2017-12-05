// 36 ms, 09/04/2017
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        multiset<info> min_vals, max_vals;
        
        for (int i = 0, n = arrays.size(); i < n; ++i) {
            min_vals.insert(info(arrays[i].front(), i));
            max_vals.insert(info(arrays[i].back(), i));
        }

        auto min_it = min_vals.begin(), max_it = prev(max_vals.end());
        if (min_it->arr_idx != max_it->arr_idx)
            return max_it->val - min_it->val;
        
        return max(abs(max_it->val - next(min_it)->val), abs(prev(max_it)->val - min_it->val));

    }
private:
    struct info {
        int val;
        int arr_idx;
        info(int val, int arr_idx) : val(val), arr_idx(arr_idx) {}
        bool operator<(const info& other) const {
            return val < other.val;
        }
    };
};
/*-------------------------------------------------------------------------*/
// TODO: Faster (19 ms) solution on leetcode
int maxDistance(vector<vector<int>>& arrays)
{
    int result = 0;
    int min_val = arrays[0][0];
    int max_val = arrays[0][arrays[0].size()-1];
    for(int i=1; i<arrays.size();i++)
    {
        result = max(result, max(abs(arrays[i][arrays[i].size()-1] - min_val), abs(max_val - arrays[i][0])));
        min_val = min(min_val, arrays[i][0]);
        max_val = max(max_val, arrays[i][arrays[i].size()-1]);
    }
    return result;

}
