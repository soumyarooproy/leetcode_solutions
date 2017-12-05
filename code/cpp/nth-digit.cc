// 3 ms, 08/31/2017
int findNthDigit(int n)
{
    // Decrement n because it is 1-indexed, while this solution is 0-indexed
    --n;
    
    // The range [10**k, 10**(k + 1)) has (k + 1) * 9 * 10**k digits
    // This range vector is precomputed
    vector<int> range({9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889});
    
    // Find out the range using binary search
    auto index = upper_bound(range.begin(), range.end(), n) - range.begin();
    
    // Compute the rest
    n -= range[index - 1];
    return to_string(pow(10, index) + (n / (index + 1)))[n % (index + 1)] - '0';
}
