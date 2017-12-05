bool checkPossibility(vector<int>& nums)
{
    if (nums.size() <= 2)
        return true;

    // sr - Sorted Range
    // |a0,   ...  ak|ak+1|ak+2 ... an-1|
    // |<----sr1---->|    |<----sr2---->|
    //               |<-------sr3------>|
    // if ak (max(sr1)) <= ak+2 ((min(sr1)), ak+1 may be modified
    // if ak+1 <= ak+2 and ak-1 < ak+1, ak may be modified
    
    auto it = is_sorted_until(nums.begin(), nums.end());
    // it will be at least (nums.begin() + 1)

    // if n or n - 1 elements are sorted, return true
    if (it >= nums.end() - 1)
        return true;

    if (!is_sorted(it + 1, nums.end()))
        return false;

    if (*(it - 1) <= *(it + 1))
        return true;

    return *it <= *(it + 1) && (it < (nums.begin() + 2) || *(it - 2) <= *it);
}
/*----------------------------------------------------------------------*/
// TODO: Faster solution on leetcode - changes the input
bool checkPossibility(vector<int>& nums) 
{
    int a = 0;
    for(int i = 0; i < nums.size()-1; i++)
    {
        if(nums[i] > nums[i+1]) 
        {
            if(i != 0) 
            {
                if(nums[i+1] < nums[i-1]) nums[i+1] = nums[i];
            }
            a++;
        }
        if(a == 2) return false;
    } 
    return true;

}
