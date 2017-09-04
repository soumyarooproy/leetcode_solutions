// Iterative
// 3 ms, 09/03/2017
int addDigits(int num)
{
    while (num >= 10) {
        auto num1 = 0;
        while (num) {
            num1 += num % 10;
            num /= 10;
        }
        num = num1;
    }
    return num;
}
/*--------------------------------------------*/
// Recursive
// 6 ms, 09/03/2017
int addDigits(int num)
{
    if (num < 10)
        return num;

    auto num1 = 0;
    while (num) {
        num1 += num % 10;
        num /= 10;
    }
    return addDigits(num1);
}
/*--------------------------------------------*/
// TODO: Constant time solution on leetcode
int addDigits(int num) {
    int result = num % 9;
    return (result || num == 0) ? result : 9;
}
