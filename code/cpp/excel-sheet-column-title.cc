string convertToTitle(int n)
{
    string result;
    while (n) {
        --n;
        result += n % 26 + 'A';
        n /= 26;
    }
    reverse(result.begin(), result.end());
    return result;
}
