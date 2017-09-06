// 3 ms, 09/06/2017
// Time  : O(n), at most 2 passes
// Space : O(1)
// TODO  : Take a look at a DP solution on leetcode
int maximumSwap(int num)
{
    auto str = to_string(num);

    // Find the first local minima (or an inflexion point) left-to-right
    int li = 0, n = str.size();
    while (li < n - 1 && str[li] >= str[li + 1])
        ++li;

    // If no local minima found, return the number unmodified
    if (li == n)
        return num;

    // Otherwise, a swap is certain; swapping the values in indices li and (li + 1)
    // will definitely give a larger number

    // But can we do better?

    // Find the max in the rest of the range, i.e. to the right of li
    int ri = n - 1, maxi = ri;
    while (ri > li) {
        if (str[ri] > str[maxi])
            maxi = ri;
        --ri;
    }

    // Swapping the values in indices li and maxi will definitely give another
    // larger number

    // But can we do even better?

    // Go back leftwards starting from li finding the max value smaller than the
    // max found above
    while (li > 0 && str[li - 1] < str[maxi])
        --li;

    swap(str[li], str[maxi]);

    return stoi(str);
}
