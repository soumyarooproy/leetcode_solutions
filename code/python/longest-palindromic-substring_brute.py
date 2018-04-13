# Date  : 04/13/2018
# Time  : O(n**3)
# Space : O(1); although this implementation uses O(n) space due to string slices

class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """

        # Search for the longest palindrome starting with length n,
        # then length (n - 1), and so on and so forth
        is_palin = lambda s : s == s[::-1]
        for l in range(len(s), 0, -1):
            for i in range(len(s) - l + 1):
                if is_palin(s[i:i+l]):
                    return s[i:i+l]

        # Will be here only if s is an empty string
        return s
