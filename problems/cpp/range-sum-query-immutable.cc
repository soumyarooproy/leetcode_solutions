// 183 ns, 08/31/2017
class NumArray {
public:
    NumArray(vector<int> nums) {
        prefix_sum.resize(nums.size());
        partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
    }
    
    int sumRange(int i, int j) {
        return prefix_sum[j] - (i ? prefix_sum[i - 1] : 0);
    }
    vector<int> prefix_sum;
};

/*-----------------------------------------------------------------*/

// 162 ns, 08/31/2017
// Avoid the branch
class NumArray {
public:
    NumArray(vector<int> nums) {
        prefix_sum.resize(nums.size() + 1);
        prefix_sum[0] = 0;
        partial_sum(nums.begin(), nums.end(), prefix_sum.begin() + 1);
    }
    
    int sumRange(int i, int j) {
        return prefix_sum[j + 1] - prefix_sum[i];
    }
    vector<int> prefix_sum;
};

/*-----------------------------------------------------------------*/

// TODO: Replace partial_sum with a for-loop to see if it speeds up the code?!
