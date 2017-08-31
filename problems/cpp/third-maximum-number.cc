// 9ms, 08/31/2017
int thirdMax(vector<int>& nums)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;
    unordered_set<int> max_nums;

    // nums is non-empty - so, at least 1 element
    min_heap.push(nums[0]); max_nums.emplace(nums[0]);

    for (auto x: nums) {
        if (!max_nums.count(x)) {
            min_heap.push(x), max_nums.emplace(x);
            if (min_heap.size() > 3) {
                max_nums.erase(min_heap.top());
                min_heap.pop();
            }
        }
    }

    if (min_heap.size() >= 3)
        return min_heap.top();

    // min_heap.size() is either 1 or 2
    auto val1 = min_heap.top();
    min_heap.pop();

    return min_heap.empty()? val1 : max(val1, min_heap.top());
}
/*------------------------------------------------------------------------*/    
// 9ms, 08/31/2017
int thirdMax(vector<int>& nums)
{
    set<int> max_nums; // increasing order BST
    for (auto x: nums) {
        max_nums.emplace(x); // no entry if x is already in the BST
        if (max_nums.size() > 3)
            max_nums.erase(max_nums.begin());
    }

    return max_nums.size() >= 3 ? *max_nums.cbegin() : *max_nums.crbegin();
}
