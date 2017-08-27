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

vector<int> findDisappearedNumbers(vector<int>& nums)
{
    for (int i = 0, n = nums.size(); i < n; ) {
        auto j = nums[i] - 1;
        if (i != j && nums[i] != nums[j])
            swap(nums[i], nums[j]);
        else
            ++i;
    }
    vector<int> missing;
    for (int i = 0, n = nums.size(); i < n; ++i)
        if (i != nums[i] - 1)
            missing.emplace_back(i + 1);

    return missing;
}

/*------------------------------------------------------------------*/
// Faster solution on leetcode
// TODO: Understand and refine
vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ret;
    for(auto  p:nums){
        auto q=abs(p);
        nums[q-1]=-abs(nums[q-1]);
    }
    for(int i=0,s=nums.size();i!=s;++i)
        if(nums[i]>0)
            ret.push_back(i+1);
    return ret;
}
