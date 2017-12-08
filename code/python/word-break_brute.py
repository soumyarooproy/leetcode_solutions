# TLE, 12/07/2017
# Time  : O((m*l)**k)
# Space : O(1)
# m = Number of words in d that are a prefix of s[s_index:] during each wordBreak() call
# l = len(w), assuming all the words in the dictionary are of the same length
# k = len(s) / l
class Solution:
    def wordBreak(self, s, d, s_index=0):
        """
        :type s: str
        :type d: List[str]
        :rtype: bool
        """
        if len(s[s_index:]) == 0:
            return True
        for w in d:
            if s.startswith(w, s_index) and self.wordBreak(s, d, s_index + len(w)):
                return True
        return False
