# 02/19/2018
# Time  : O(n + m*lgk), m is the number of distinct words
# Space : O(m + k)

class Solution:
    import functools
    @functools.total_ordering
    class HeapEntry:
        def __init__(self, x):
            self.freq, self.word = x
        def __lt__(self, other):
            return self.freq < other.freq or self.freq == other.freq and other.word < self.word
        def __eq__(self, other):
            return self.freq == other.freq and self.word == self.word
        
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        
        # Create word->freq map
        import collections
        word_freq = collections.defaultdict(int)
        for w in words:
            word_freq[w] += 1
        
        # Insert word_freq entries into a min-heap of size k; if size becomes
        # k + 1, pop the top of the heap
        min_heap = []
        for word, freq in word_freq.items():
            heapq.heappush(min_heap, Solution.HeapEntry((freq, word)))
            if len(min_heap) > k:
                heapq.heappop(min_heap)

        # Pop heap contents and return them in reverse order
        return list(reversed([heapq.heappop(min_heap).word for _ in range(len(min_heap))]))
