// 9 ms, 08/29/2017
bool isPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; ) {
        bool alnum_i = isalnum(s[i]), alnum_j = isalnum(s[j]);
        if (alnum_i && alnum_j) {
            if (tolower(s[i++]) != tolower(s[j--]))
                return false;
        } else {
            if (!alnum_i)
                ++i;
            if (!alnum_j)
                --j;                
        }
    }
    return true;
}
/*------------------------------------------------------------------------*/
// More concise code on leetcode - 9ms
bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        while (!isalnum(s[i]) && i < j) ++i;
        while (!isalnum(s[j]) && i < j) --j;
        if (toupper(s[i]) != toupper(s[j])) return false;
    }
    return true;
}
