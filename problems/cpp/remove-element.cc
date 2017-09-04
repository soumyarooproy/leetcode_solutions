// 3 ms, 09/03/2017
int removeElement(vector<int>& nums, int val)
{
    int write_i, n = nums.size();

    // Find the first delete position
    for (write_i = 0; write_i < n && nums[write_i] != val; ++write_i);

    for (int read_i = write_i + 1; read_i < n; ) {
        // Skip all the elements to be deleted
        for (; read_i < n && nums[read_i] == val; ++read_i);
        // Perform compaction till an element to be deleted is encountered
        for ( ; read_i < n && nums[read_i] != val; nums[write_i++] = nums[read_i++]);
    }

    return write_i;
}
/*-------------------------------------------------------*/
// TODO: Cleaner solution on leetcode
int removeElement(vector<int>& nums, int val) {
    // two pointers
    // answers are to the left of s
    int s = 0;
    for (int f = 0; f < nums.size(); ++f) {
        if (nums[f] != val) {
            nums[s] = nums[f];
            ++s;
        } 
    }
    return s;
}
