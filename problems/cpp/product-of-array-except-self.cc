// To compute:
//     result[i] = prod(A[0 .. (i - 1)]) * prod(A[(i + 1) .. (n - i)])
vector<int> productExceptSelf(vector<int>& nums)
{
    vector<int> result (nums.size(), 1);

    // First pass, left to right, compute
    //     result[i] = prod(A[0 .. (i - 1)])
    for (int i = 1; i < nums.size(); ++i)
        result[i] = nums[i - 1]*result[i - 1];

    // Second pass, right to left, compute
    //     result[i] *= prod(A[(i + 1) .. (n - i)])
    for (int i = nums.size() - 2, prod = 1; i >= 0; --i) {
        prod *= nums[i + 1];
        result[i] *= prod;
    }

    return result;
}
/*-----------------------------------------------------------*/
// TODO: Combine the two passes above into 1
