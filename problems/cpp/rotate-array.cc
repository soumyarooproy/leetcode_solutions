// Problem description URL: https://leetcode.com/problems/rotate-array

// 19 ms, 08/29/2017
void rotate(vector<int>& nums, int k)
{
    k %= nums.size();
    if (!k)
        return;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}
/*--------------------------------------------------------*/
// TODO: Look up the solution on EPI
// TODO: Look up the reference implementation of std::rotate()
// 26 ms, 08/29/2017
void rotate(vector<int>& nums, int k)
{
    k %= nums.size();
    if (!k)
        return;
    std::rotate(nums.begin(), nums.begin() + nums.size() - k, nums.end());
}
