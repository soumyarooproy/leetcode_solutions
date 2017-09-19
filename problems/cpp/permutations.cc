class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> result;
        permute_recursive(0, &nums, &result);
        return result;
    }
private:
    void permute_recursive(int depth, vector<int>* arr, vector<vector<int>>* result)
    {
        if (depth == arr->size() - 1) {
            result->emplace_back(*arr);
            return;
        }
        for (int i = depth, n = arr->size(); i < n; ++i) {
            swap((*arr)[depth], (*arr)[i]);
            permute_recursive(depth + 1, arr, result);
            swap((*arr)[depth], (*arr)[i]);
        }
    }
};
