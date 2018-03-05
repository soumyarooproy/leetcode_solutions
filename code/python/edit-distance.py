# 03/05/2018
# Time  : O(m*n)
# Space : O(m*n); Can probably be optimized to O(m+n) or O(max(m, n))
# Notes : https://en.wikipedia.org/wiki/Levenshtein_distance

class Solution:
    from functools import lru_cache
    
    @lru_cache(maxsize=None)
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if not word1 or not word2:
            return max(len(word1), len(word2))
        return (self.minDistance(word1[1:], word2[1:]) if word1[0] == word2[0]
                else 1 + min(self.minDistance(word1, word2[1:]),     # insert  word2[0] in word1
                             self.minDistance(word1[1:], word2[1:]), # replace word1[0] with word2[0]
                             self.minDistance(word1[1:], word2)      # delete  word1[0] from word1
                            )
               )
