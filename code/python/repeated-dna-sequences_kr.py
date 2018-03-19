# Date  : 3/19/2018
# Time  : O(n*k), k is 10 in this case
# Space : O(m), m is the number of distinct k-long substrings in the input
# Notes : Uses Karp-Rabin sort of rolling hash; the hash size is still k in size in this
#         implementation and, therefore, not an improvement in big-Oh

class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        ENC = {'A' : 0, 'C' : 1, 'G' : 2, 'T' : 3}
        DEC = ['A', 'C', 'G', 'T']
        K = 10
        MASK_U = (1 << 2 * (K - 1)) - 1
        MASK_L = 0x3

        def encode_prefix():
            h = 0
            for c in s[:K]:
                h  = (h << 2) | ENC[c]
            return h

        def decode(h):
            l = [None for _ in range(K)]
            for i in range(K):
                l[K - 1 - i] = DEC[h & MASK_L]
                h >>= 2
            return ''.join(l)

        counts = collections.defaultdict(int)
        h = encode_prefix()
        counts[h] += 1
        
        # Now, iterate over the rest of the sequence and apply rolling hash/encoding
        for i, c in enumerate(s[K:], 1):
            h = ((h & MASK_U) << 2) | ENC[c]
            counts[h] += 1
        
        return [decode(key) for key, val in counts.items() if val > 1]
