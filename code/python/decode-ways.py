# 03/06/2018
# Time  : O(n)
# Space : O(n)

class Solution:
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        
        from functools import lru_cache
        @lru_cache(maxsize=None)
        def num_decodings(s):
            if not s or len(s) == 1 and s != '0':
                return 1
            if s[0] == '0':
                return 0
            return num_decodings(s[1:]) + (num_decodings(s[2:]) if int(s[:2]) <= 26 else 0)
        
        return num_decodings(s)
