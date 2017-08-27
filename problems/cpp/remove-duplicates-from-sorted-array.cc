int removeDuplicates(vector<int>& nums)
{
    if (nums.size() < 2)
        return nums.size();

    auto write_i = 0;
    for (auto read_i = 1; read_i < nums.size(); ++read_i) {
        if (nums[read_i] != nums[write_i])
            nums[++write_i] = nums[read_i];
    }
    return write_i + 1;
}

/*-------------------------------------------------------------*/

int removeDuplicates_cheat(vector<int>& nums)
{
    auto end = unique(nums.begin(), nums.end());
    return distance(nums.begin(), end);
}
