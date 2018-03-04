# 03/03/2018
# Time  : O(n*m)
# Space : O(n*m)
# Notes : Memoized version of regular-expression-matching_recur.py

class Solution:
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        from functools import lru_cache
        @lru_cache(maxsize=None)        
        def is_match_recur(s_index, p_index, depth=0):
            # If pattern is exhausted, string should be exhausted
            if p_index == len(p):
                return s_index == len(s)
            
            # Otherwise, if string is exhausted, the remaining pattern
            # should be able to match 0 characters
            if s_index == len(s):
                return p_index + 1 < len(p) and p[-1] == '*' and all(c == '*' for c in p[p_index + 1::2])
            
            # Function to match a single char
            match_char = lambda s_index, p_index : p[p_index] == '.' or s[s_index] == p[p_index]

            # Check if the next char in the string is an asterisk '*'
            if p_index + 1 < len(p) and p[p_index + 1] == '*':
                if match_char(s_index, p_index):
                    # Match 1 string char with two pattern chars but do not exhaust the pattern chars
                    if is_match_recur(s_index + 1, p_index, depth + 1):
                        return True
                # Match 0 string chars with two pattern chars and exhaust the pattern chars
                return is_match_recur(s_index, p_index + 2, depth + 1)
            
            # Otherwise, match 1 string char with 1 pattern char
            return match_char(s_index, p_index) and is_match_recur(s_index + 1, p_index + 1, depth + 1)
        
        return is_match_recur(0, 0)
