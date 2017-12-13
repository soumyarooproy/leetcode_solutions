class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        """
            Let L[i] store the longest valid paren string with s[i] as the last char

            L[i] = 0, if s[i] is '('
                 = the length of the paren string s[i] terminates, say k, + L[i - k], if s[i] is ')'
            Use a stack to store the indices of the '(' chars
            
            L[-1] = 0
            
            return max(L) as the answer
        """
        L = [0] # indices go from 0..n instead of -1..(n - 1) as described above
        stack = []
        for i in range(len(s)):
            if s[i] == ')':
                if stack:
                    j = stack.pop()
                    L.append(i - j + 1 + L[j])
                else:
                    L.append(0)
            else: # s[i] == '('
                stack.append(i)
                L.append(0)
                
        return max(L)
