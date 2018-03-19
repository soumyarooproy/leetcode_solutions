# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n) this implementation; could be make O(1) easily

class Solution(object):
    def shortestDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        matches1, matches2 = [], []
        for i, word in enumerate(words):
            if word == word1:
                matches1.append(i)
            if word == word2:
                matches2.append(i)           
        
        min_dist, i, j = float('inf'), 0, 0
        while i < len(matches1) and j < len(matches2):
            min_dist = min(min_dist, abs(matches1[i] - matches2[j]))
            if matches1[i] < matches2[j]:
                i += 1
            else: # matches1[i] > matches2[j]
                j += 1
        
        return min_dist
