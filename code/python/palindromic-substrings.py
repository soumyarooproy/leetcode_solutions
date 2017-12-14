"""
219 ms, 12/14/2017
Time  : O(n^2)
Space : O(1)
"""
class Solution:
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = 0
        n = len(s)
        for i in range (n):
            """ Odd length palindromes centered at i """
            j = 0
            while (i >= j) and (i + j < n) and s[i - j] == s[i + j]:
                #print('({}, {}) = {}'.format(i, j, s[i - j:i + j + 1]))
                count += 1
                j += 1
            """ Even length palindromes centered between i and (i+1) """
            j = 1
            while (i >= j - 1) and (i + j < n) and s[i - j + 1] == s[i + j]:
                #print('({}, {}) = {}'.format(i, j, s[i - j + 1:i + j + 1]))
                count += 1
                j += 1

        return count
