# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n)
# Notes : Found this solution on Leetcode

class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        def encoded_str(s):
            char_map, l = {}, []
            for c in s:
                if not c in char_map:
                    char_map[c] = len(char_map)
                l.append(char_map[c])
            #print('s =', s, 'l =', l)
            return l

        return encoded_str(s) == encoded_str(t)
