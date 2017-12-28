# TLE, 12/27/2017
# Time  : O(n^3)
# Space : O(1)
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        """
            Exhaustively search through all the substrings of s in longest
            (||s|| chars) to shortest (1 char) order; terminate search when
            the first substring with all unique characters is found. Use a
            set to determine if a substring has duplicate chars.
        """
        for l in reversed(range(1, len(s) + 1)):
            # Set creation from string s is O(n) operation
            if any(len(set(s[i:i+l])) == l for i in range(len(s) - l + 1)):
                return l
        return 0
