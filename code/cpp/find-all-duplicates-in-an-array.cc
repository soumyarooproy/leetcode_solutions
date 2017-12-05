/*
    x = 4,  [4,3,2,7,8,2,3,1] []
    x = 3,  [4,3,2,-7,8,2,3,1] []
    x = -2, [4,3,-2,-7,8,2,3,1] []
    x = -7, [4,-3,-2,-7,8,2,3,1] []
    x = 8,  [4,-3,-2,-7,8,2,-3,1] []
    x = 2,  [4,-3,-2,-7,8,2,-3,-1] [2]
    x = -3, [4,3,-2,-7,8,2,-3,-1] [2, 3]
    x = -1, [4,-3,-2,-7,8,2,-3,-1] [2, 3]
    final,  [-4,-3,-2,-7,8,2,-3,-1] [2, 3]
*/

vector<int> findDuplicates(vector<int>& nums)
{
    vector<int> duplicates;

    for (auto x : nums) {
        auto y = abs(x), z = y - 1;
        if (nums[z] < 0)
            duplicates.emplace_back(y);
        else
            nums[z] = -nums[z];
    }

    return duplicates;
}

/*-------------------------------------------------------------------*/
// Use the array as a table and rearrange the numbers so that a[i - 1] = i
/*
    [4,3,2,7,8,2,3,1]
    swap(0, A[0] - 1) -> [7,3,2,4,8,2,3,1]
    swap(0, A[0] - 1) -> [3,3,2,4,8,2,7,1]
    swap(0, A[0] - 1) -> [2,3,3,4,8,2,7,1]
    swap(0, A[0] - 1) -> [3,2,3,4,8,2,7,1]
    swap(4, A[4] - 1) -> [3,2,3,4,1,2,7,8]
    swap(4, A[4] - 1) -> [1,2,3,4,3,2,7,8]
*/
vector<int> findDuplicates(vector<int>& nums)
{
    for (int i = 0, n = nums.size(); i < n; ) {
        auto j = nums[i] - 1;
        if (i != j && nums[i] != nums[j])
            swap(nums[i], nums[j]);
        else
            ++i;
    }

    vector<int> duplicates;
    for (int i = 0, n = nums.size(); i < n; ++i)
        if (i != nums[i] - 1)
            duplicates.emplace_back(nums[i]);

    return duplicates;
}

/*-------------------------------------------------------------------*/

vector<int> findDuplicates(vector<int>& nums) {
    unordered_set<int> table;
    vector<int> duplicates;
    for (auto i : nums) {
        if (!table.emplace(i).second)
            duplicates.emplace_back(i);
    }
    return duplicates;
}
