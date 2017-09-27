// 9 ms, 09/26/2017
// Time  : O(n lg k)
// Space : O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for (auto x : nums)
            if (heap.size() < k || heap.top() < x) {
                heap.push(x);
                if (heap.size() > k)
                    heap.pop();
            }
        return heap.top();
    }
};
/*---------------------------------------------------------------------------*/
// Cleaner code
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap(nums.begin(), nums.begin() + k);
        for (int i = k, n = nums.size(); i < n; ++i)
            if (heap.top() < nums[i]) {
                heap.push(nums[i]);
                heap.pop();
            }
        return heap.top();
    }
};
/*---------------------------------------------------------------------------*/
// Linear solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), std::greater<int>());
        return nums[k - 1];
    }
};
