// 6 ms, 09/17/2017
// Time  : O(lg n), 2 passes
// Space : O(1)
// TODO  : Do in a single pass; refer to code below
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if (!nums.size())
            return -1;
        
        // find min index
        int n = nums.size(), lb = 0, ub = n - 1;
        while (lb < ub) {
            int mid = lb + (ub - lb) / 2;
            if (nums[mid] > nums[ub]) {
                lb = mid + 1;
            } else {
                ub = mid;
            }
        }
        
        // target is either in range [min_index, n - 1] or in range [0, min_index - 1]
        if (target > nums.back()) {
            ub = (lb - 1) % n;
            lb = 0;
        } else {
            ub = n - 1;
        }
        while (lb < ub) {
            int mid = lb + (ub - lb) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target) {
                lb = mid + 1;
            } else {
                ub = mid - 1;
            }
        }
        return nums[lb] == target ? lb : -1;
    }
};
/*-------------------------------------------------------------*/
// Single pass solution on leetcode
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] < nums[low]) {
                if (target > nums[mid] && target <= nums[high])
                    low = mid + 1;
                else 
                    high = mid - 1;
            } else {
                if (target >= nums[low] && target < nums[mid])
                    high = mid - 1;
                else 
                    low = mid + 1;
            }
        }
        return -1;
    }
};
