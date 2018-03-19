# Date  : 3/19/2018
# Time  : O(n*k), k is 10 in this case
# Space : O(m), m is the number of distinct k-long substrings in the input

class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        K = 10
        counts = collections.defaultdict(int)
        for i in range(len(s) - (K - 1)):
            substr = s[i : i + K]
            counts[substr] += 1
        
        return [key for key in counts if counts[key] > 1]
