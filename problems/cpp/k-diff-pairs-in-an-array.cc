// 56 ms, 08/31/2017
struct hash_pair
{
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ ((hash<int>()(p.second)) << 1);
    }
};

int findPairs(vector<int>& nums, int k)
{
    if (k < 0)
        return 0;

    unordered_set<int> nums_set;
    unordered_set<pair<int, int>, hash_pair> pairs_set;

    for (auto x : nums) {
        if (nums_set.count(x - k))
            pairs_set.emplace(minmax(x, x - k));
        if (k && nums_set.count(k + x))
            pairs_set.emplace(minmax(x, k + x));
        nums_set.emplace(x);
    }

    return pairs_set.size();
}

/*------------------------------------------------------------------------------*/
// TODO: Faster solution on leetcode; 26 ms
int findPairs(vector<int>& nums, int k) {
    int len = nums.size();
    //special cases.
    if(len < 2 || k < 0) return 0;
    sort(nums.begin(), nums.end());
    int cnt = 0, left = 0, right = 1;
    while(right < len){
        if(nums[right] - nums[left] < k)
            ++right;
        else if(nums[right] - nums[left] > k)
            ++left;
        else{
            ++cnt;
            ++left;
            ++right;
            //skip the same num.
            while(left < len && nums[left-1] == nums[left])
                ++left;
            while(right < len && nums[right-1] == nums[right])
                ++right;
        }
        if(left == right) ++right;
    }
    return cnt;
}
