bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    string str = to_string(x);
    string rev_str(str.crbegin(), str.crend());
    return str == rev_str;
}
/*-----------------------------------------------------------------*/
bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int rev_x = 0, x_copy = x;
    while (x) {
        rev_x *= 10;
        rev_x += x % 10;
        x /= 10;
    }

    return rev_x == x_copy;
}
/*-----------------------------------------------------------------*/
bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    string str = to_string(x);
    auto mid = str.cbegin() + str.size() / 2;
    return mismatch(str.cbegin(), mid, str.crbegin()).first == mid;
}
/*-----------------------------------------------------------------*/
bool isPalindrome(int x)
{
    if (x < 0)
        return false;

    int n = static_cast<int>(floor(log10(x)) + 1);
    int msd_mask = static_cast<int>(pow(10, n - 1));
    for (int i = 0; i < n / 2; ++i) {
        if (x / msd_mask != x % 10)
            return false;
        x %= msd_mask;
        x /= 10;
        msd_mask /= 100;
    }
    return true;
}
