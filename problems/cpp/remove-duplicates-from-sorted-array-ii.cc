// 13 ms, 09/20/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (!nums.size())
            return 0;
        int i_write = 0;
        for (int i_read = 1, count = MAX_DUPLICATES, n = nums.size(); i_read < n; ++i_read) {
            if (nums[i_write] == nums[i_read]) {
                // Duplicate element
                if (count - 1)
                    nums[++i_write] = nums[i_read], --count;
            } else {
                // New element
                nums[++i_write] = nums[i_read];
                count = MAX_DUPLICATES;
            }
        }
        return i_write + 1;
    }
private:
    const static int MAX_DUPLICATES = 2;
};
/*-----------------------------------------------------------------------*/
// More compact solution on leetcode
class Solution {
  public:
      int removeDuplicates(vector<int>& nums) {
          if (nums.size() <= 2) return nums.size();
          int index = 2;
          for (int i = 2; i < nums.size(); i++){
              if (nums[i] != nums[index - 2])
                  nums[index++] = nums[i];
}
          return index;
      }
};
