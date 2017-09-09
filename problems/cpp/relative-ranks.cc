// 12 ms, 09/09/2017
// Time  : O(n lg n)
// Space : O(n)
// TODO  : Try BST/Heap; no change in perf through
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&nums] (const int i, const int j) { return nums[i] > nums[j]; });

        vector<string> result(n);
        
        if (n)
            result[indices[0]] = "Gold Medal";
        if (n > 1)
            result[indices[1]] = "Silver Medal";
        if (n > 2)
            result[indices[2]] = "Bronze Medal";
        for (int i = 3; i < n; ++i)
            result[indices[i]] = to_string(i + 1);
        return result;
    }
};
