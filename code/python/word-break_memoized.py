# 03/01/2018
# Time  : O(??)
# Space : O(n)

class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        from functools import lru_cache
        @lru_cache(maxsize=None)
        def word_break_helper(index):
            if index == len(s):
                return True
            for word in wordDict:
                if s.startswith(word, index) and word_break_helper(index + len(word)):
                    return True
            return False
        return word_break_helper(0)
