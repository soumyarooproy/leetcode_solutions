// 6 ms, 09/13/2017
// Time  : O(n1 + n2)
// Space : O(m1 + m2)
// TODO  : Sort the arrays to achieve O(1) space (and skip duplicates)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> set1(nums1.begin(), nums1.end()), set2(nums2.begin(), nums2.end());
        vector<int> intersection;
        for (auto x : set2)
            if (set1.count(x))
                intersection.emplace_back(x);
        
        return intersection;
    }
};
