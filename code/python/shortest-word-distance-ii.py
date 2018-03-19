# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n) for both init and queries
# Notes : O(n^2) in init and O(1) for each query fails on OJ

class WordDistance(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.indices = collections.defaultdict(list)
        for i, word in enumerate(words):
            self.indices[word].append(i)

    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1, l2 = self.indices[word1], self.indices[word2]
        i, j, min_dist = 0, 0, float('inf')
        
        while i < len(l1) and j < len(l2):
            min_dist = min(min_dist, abs(l1[i] - l2[j]))
            if l1[i] < l2[j]:
                i += 1
            else:
                j += 1
        
        return min_dist

# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
