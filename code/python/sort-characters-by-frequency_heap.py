# 02/19/2018
# Time  : O(n + m*lgm), m is the number of distinct characters in the input string
# Space : O(n + m)

class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """

        # Compute char->freq map
        import collections
        freq = collections.defaultdict(int)
        for c in s:
            freq[c] += 1

        # Use a max-heap to sort the map entries by frequency
        max_heap = []
        for c, count in freq.items():
            heapq.heappush(max_heap, (-count, c))
        res = ''
        while max_heap:
            count, c = heapq.heappop(max_heap)
            res += c*(-count)
        
        return res
