// 139 ms, 09/25/2017
// Time  : O(n)
// Space : O(n)
// TODO  : Faster solutions below
class Solution {
public:
    bool validPalindrome(string s)
    {
        return valid_palindrome(s, 0, s.size() - 1, 1);
    }
private:
    bool valid_palindrome(const string& s, int left, int right, int num_dels)
    {
        if (left < right && s[left] != s[right])
            return num_dels
                   && (valid_palindrome(s, left + 1, right, num_dels - 1)
                       || valid_palindrome(s, left, right - 1, num_dels - 1));
        return left >= right || valid_palindrome(s, left + 1, right - 1, num_dels);
    }
};
/*-------------------------------------------------------------------------*/
// 109 ms
class Solution {
public:
    bool validPalindrome(const string& s, int i, int j) {
        for(; i < j; ++i, --j)
             if (s[i] != s[j])
                 return false;
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        for(; i < j; ++i, --j) {
            if (s[i] != s[j])
                break;
        }
        if (i >= j)
            return true;
        if (validPalindrome(s, i+1, j) || validPalindrome(s, i, j -1))
            return true;
        return false;       
    }
};
/*-------------------------------------------------------------------------*/
// 115 ms
class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size(), i = 0, j = n-1;
        while (i < j && s[i] == s[j]) i++, j--;
        return isvalid(s, i+1, j) || isvalid(s, i, j-1);
    }
private:
    bool isvalid(string& s, int l, int r) {
        while (l < r && s[l] == s[r]) l++, r--;
        return l >= r;
    }
};
