// 3 ms, 09/11/2017
// Time  : O(n)
// Space : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int i_left = 0, i_right = numbers.size() - 1;
        while (i_left < i_right) {
            int sum = numbers[i_left] + numbers[i_right];
            if (sum == target)
                return {i_left + 1, i_right + 1};
            if (sum < target)
                ++i_left;
            else
                --i_right;
        }
        return {0, 0};
    }
};
