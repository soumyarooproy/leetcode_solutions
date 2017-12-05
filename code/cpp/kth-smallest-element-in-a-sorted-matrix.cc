// 43 ms, 09/26/2017
// Time  : O(n^2 lg k)
// Space : O(k)
// TODO  : Use binary search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        priority_queue<int> heap;
        for (auto& r : matrix)
            for (auto i : r)
                if (heap.size() < k || heap.top() > i) {
                    heap.push(i);
                    if (heap.size() > k)
                        heap.pop();
                }
        return heap.top();
    }
};
