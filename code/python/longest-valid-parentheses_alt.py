# 03/04/2018
# Time  : O(n)
# Space : O(n)

class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # Let C[i] be the length of the longest valid (well-formed) parentheses
        # substring ending at s[i]:
        # C[i] = k + C[i - k], where k is the size of the parenthesized string completed by s[i]
        #      = 0           , if s[i] is '(' because '(' does not complete any parenthesized string
        # E.g.:
        # '()()' -> C = [0, 2, 0, 4]
        
        st, C = [], []
        for i, c in enumerate(s):
            if c == ')':
                cur_len = (i - st.pop() + 1) if st else 0
                C.append(cur_len + (C[-cur_len] if cur_len < len(C) else 0))
            else: # c == '('
                st.append(i)
                C.append(0)

        return max(C, default=0)
