// 6 ms, 09/13/2017
// Time  : O(n1 + n2)
// Space : O(m1 + m2)
// TODO  : Sort arrays to achieve O(1) space
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> map1, map2;
        for (auto x : nums1)
            ++map1[x];
        for (auto x : nums2)
            ++map2[x];
        
        vector<int> intersection;
        for (auto x : map2)
            if (map1.count(x.first))
                for (int i = 0, n = min(x.second, map1[x.first]); i < n; ++i)
                    intersection.emplace_back(x.first);
        
        return intersection;
    }
};
/*--------------------------------------------------------------------------------*/
// 6 ms, 09/13/2017
// Time  : O(n1 + n2)
// Space : O(m1)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> map1;
        for (auto x : nums1)
            ++map1[x];
        vector<int> intersection;
        for (auto x : nums2) {
            auto end = map1.end(), it = end;
            if ((it = map1.find(x)) != end) {
                intersection.emplace_back(x);
                if (!--it->second)
                    map1.erase(it);
            }
        }
        
        return intersection;
    }
};
