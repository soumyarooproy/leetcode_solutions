// 3 ms, 09/06/2017
// Time  : O(n), at most 2 passes
// Space : O(1)
// TODO  : Take a look at a DP solution on leetcode
int maximumSwap(int num)
{
    auto str = to_string(num);

    // Find the first local minima (or an inflexion point) left-to-right
    int n = str.size(), li = 0;
    for ( ; li < n - 1 && str[li] >= str[li + 1]; ++li);

    // If no local minima found, return the number unmodified
    if (li == n)
        return num;

    // Find the max in the rest of the range, i.e. to the right of li
    int maxi = n - 1;
    for (int ri = maxi - 1; ri > li; --ri)
        if (str[ri] > str[maxi])
            maxi = ri;

    // Go back leftwards starting from li finding the max value smaller than the
    // max found above
    for ( ; li > 0 && str[li - 1] < str[maxi]; --li);

    swap(str[li], str[maxi]);

    return stoi(str);
}
