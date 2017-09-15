// 9 ms, 09/14/2017
// Time  : O(n)
// Space : O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        stack<int> s;
        unordered_map<int, int> m;
        for (auto x : nums) {
            while (!s.empty() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int> res;
        for (auto x : findNums)
            res.push_back(m.count(n) ? m[n] : -1);
        return res;
    }
};
