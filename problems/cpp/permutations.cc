// 9 ms, 09/19/2017
// Time  : O(n!)
// Space : O(n)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        permute_recursive(0, &nums, &result);
        return result;
    }
private:
    void permute_recursive(int index_start, vector<int>* arr, vector<vector<int>>* result)
    {
        if (index_start == arr->size() - 1) {
            result->emplace_back(*arr);
            return;
        }
        for (int i = index_start, n = arr->size(); i < n; ++i) {
            swap((*arr)[index_start], (*arr)[i]);
            permute_recursive(index_start + 1, arr, result);
            swap((*arr)[index_start], (*arr)[i]);
        }
    }
};
