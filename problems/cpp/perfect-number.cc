// 3 ms, 09/04/2017
bool checkPerfectNumber(int num)
{
    if (num <= 1)
        return false;

    int sqrt_n = ceil(sqrt(num)), sum = 1;
    for (int i = 2; i < sqrt_n; ++i) {
        if (num % i == 0)
            sum += i + num / i;
    }
    if (sqrt_n * sqrt_n == num)
        sum += sqrt_n;

    return sum == num;
}
