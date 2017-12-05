// 3ms, 09/03/2017
bool isUgly(int num)
{
    if (!num)
        return 0;

    for ( ; num % 2 == 0; num /= 2);
    for ( ; num % 3 == 0; num /= 3);
    for ( ; num % 5 == 0; num /= 5);

    return num == 1;
}
