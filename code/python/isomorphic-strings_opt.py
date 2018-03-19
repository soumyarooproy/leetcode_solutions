# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n)
# Notes : Found this solution on Leetcode

class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return len(set(zip(s, t))) == len(set(s)) == len(set(t))
