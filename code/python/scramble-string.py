# 03/05/3018
# Time  : O(n*n), n = len(s1) = len(s2) 
# Space : O(n*n)
# Notes : Memoization using the @lru_cache decorator

class Solution:
    from functools import lru_cache
    
    @lru_cache(maxsize=None)
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        from collections import Counter
        if s1 == s2:
            return True
        if Counter(s1) != Counter(s2): # or compare sorted strings
            return False
        if len(s1) <= 2 or len(s2) <= 2:
            return s1 == s2[::-1]
        for i in range(1, len(s1)):
            if (self.isScramble(s1[:i], s2[:i]) and self.isScramble(s1[i:], s2[i:])
                or self.isScramble(s1[:i], s2[-i:]) and self.isScramble(s1[i:], s2[:-i])):
                return True
        return False
