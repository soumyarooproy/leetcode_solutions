// 39 ms, 09/14/2017
// Time  : O(m * n)
// Space : O(1)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c)
    {
        int rows = nums.size();
        int cols = rows ? nums[0].size() : 0;
        if (r < 0 && c < 0 || r == rows && c == cols || rows * cols != r * c)
            return nums;
        
        vector<vector<int>> reshaped;
        reshaped.reserve(r);
        for (int i = 0, count = -1; i < rows; ++i)
            for (auto x : nums[i]) {
                if (!(++count % c)) {
                    reshaped.push_back({});
                    reshaped.back().reserve(c);
                }
                reshaped.back().push_back(x);
            }
        return reshaped;
    }
};
