# Date  : 03/18/2018
# Time  : O(n)
# Space : O(n)
# Notes : Refer to isomorphic-strings.py for an alternate approach 

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
            return l

        return encoded_str(s) == encoded_str(t)
