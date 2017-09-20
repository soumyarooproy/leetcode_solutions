// 23 ms, 09/19/2017
// Time  : O(n!)
// Space : O(n)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        permute_unique_recursive(0, &nums, &result);
        return result;
    }
private:
    void permute_unique_recursive(int index_start, vector<int>* arr, vector<vector<int>>* result)
    {
        vector<int>& a = *arr;
        if (index_start == arr->size() - 1) {
            result->emplace_back(a);
            return;
        }
        permute_unique_recursive(index_start + 1, arr, result);
        for (int i = index_start + 1, n = arr->size(); i < n; ++i) {
            if (a[index_start] == a[i])
                continue;
            swap(a[index_start], a[i]);
            permute_unique_recursive(index_start + 1, arr, result);
        }
        rotate(a.begin() + index_start, a.begin() + index_start + 1, a.end());
    }
};
/*----------------------------------------------------------------------------------*/
// Simpler solution
// Space : O(n^2)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        permute_unique_recursive(0, nums, &result);
        return result;
    }
private:
    void permute_unique_recursive(int index_start, vector<int> a, vector<vector<int>>* result)
    {
        if (index_start == a.size() - 1) {
            result->emplace_back(a);
            return;
        }
        permute_unique_recursive(index_start + 1, a, result);
        for (int i = index_start + 1, n = a.size(); i < n; ++i) {
            if (a[index_start] == a[i])
                continue;
            swap(a[index_start], a[i]);
            permute_unique_recursive(index_start + 1, a, result);
        }
    }
};
