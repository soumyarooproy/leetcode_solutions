// 3 ms, 09/06/2017
// Time  : O(n)
// Space : O(1)
bool checkRecord(string s)
{
    int num_a = 0, num_l = 0;
    for (auto x : s) {
        if (x == 'A' && num_a++)
            return false;
        if (x == 'L') {
            if (2 == num_l++)
                return false;
        } else if (num_l)
            num_l = 0;
    }
    return true;
}
