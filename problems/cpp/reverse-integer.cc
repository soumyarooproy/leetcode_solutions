// 15 ms, 09/01/2017
int reverse(int x)
{
    int mult = x < 0 ? -1 : 1;
    x = abs(x);

    long y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    y *= mult;

    if (y > numeric_limits<int>::max() || y < numeric_limits<int>::min())
        return 0;

    return y;
}
