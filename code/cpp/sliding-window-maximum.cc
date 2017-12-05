// 76 ms, 09/27/2017
// Time  : O(n lg k)
// Space : O(k)
// TODO  : (1) Use a heap; (2) Solve in O(n) time
using std::multiset;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        int n = nums.size();
        if (!n)
            return {};
        vector<int> max;
        max.reserve(n - k);
        multiset<int> sorted_window(nums.begin(), nums.begin() + k);
        max.push_back(*sorted_window.crbegin());
        for (int i = 0; i < n - k; ++i) {
            sorted_window.emplace(nums[i + k]);
            sorted_window.erase(sorted_window.find(nums[i])); // erase just one copy in case of duplicates
            max.push_back(*sorted_window.crbegin());
        }
        return max;
    }
};
