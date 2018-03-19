# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n); could be made O(1)

class Solution(object):
    def shortestWordDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        indices = collections.defaultdict(list)
        for i, word in enumerate(words):
            if word == word1 or word == word2:
                indices[word].append(i)

        if word1 == word2:
            l = indices[word1]
            return min(x - y for x, y in zip(l[1:], l[:-1]))
        
        l1, l2 = indices[word1], indices[word2]
        min_dist, i, j = float('inf'), 0, 0
        while i < len(l1) and j < len(l2):
            min_dist = min(min_dist, abs(l1[i] - l2[j]))
            if l1[i] < l2[j]:
                i += 1
            else: # l1[i] > l2[j]
                j += 1
        
        return min_dist
