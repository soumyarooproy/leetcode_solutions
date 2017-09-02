// 6 ms, 09/02/2017
bool two_sum(const vector<int>& v, int sum)
{
    int left_i = 0, right_i = v.size() - 1;
    while (left_i <= right_i) {
        auto temp_sum = v[left_i] + v[right_i];
        if (temp_sum == sum)
            return true;
        if (temp_sum > sum)
            --right_i;
        else
            ++left_i;
    }
    return false;
}

bool judgeSquareSum(int c)
{
    auto n = floor(sqrt(c));
    vector<int> squares(n + 1);
    int i = 0;
    generate(squares.begin(), squares.end(), [&i] () { return i * i++; });
    return two_sum(squares, c);
}
/*------------------------------------------------------------------------*/
// 3 ms, 09/02/2017
bool judgeSquareSum(int c)
{
    auto n = floor(sqrt(c));
    int left = 0, right = n;
    while (left <= right) {
        auto sum = left*left + right*right;
        if (sum == c)
            return true;
        if (sum < c)
            ++left;
        else
            --right;
    }
    return false;
}
