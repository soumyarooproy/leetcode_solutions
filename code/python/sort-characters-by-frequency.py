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

        # Sort map entries by freq and then reconstruct the string
        return ''.join(c*count for c, count in sorted(list(freq.items()), key=lambda x : x[1], reverse=True))
