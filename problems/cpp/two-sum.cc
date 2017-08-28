vector<int> twoSum(vector<int>& nums, int target)
{
    vector<int> indices(nums.size());
    iota(indices.begin(), indices.end(), 0);

    sort(indices.begin(), indices.end(), [&nums] (const int& i, const int&j) { return nums[i] < nums[j]; });

    int left_index = 0, right_index = nums.size() - 1;
    while (left_index < right_index) {
        int sum = nums[indices[left_index]] + nums[indices[right_index]];
        if (sum == target)
            return vector<int>({indices[left_index], indices[right_index]});
        if (sum < target)
            ++left_index;
        else
            --right_index;
    }
    return vector<int>();
}
/*----------------------------------------------------------------------*/
vector<int> twoSum(vector<int>& nums, int target)
{
    std::unordered_map<int, int> remMap;

    for (size_t i = 0; i < nums.size(); ++i) {
        if (remMap.count(target - nums[i])) {
            return {remMap[target - nums[i]], i};
        } else {
            remMap[nums[i]] = i;
        }
    }
    return {-1, -1};
}    
