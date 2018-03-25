# Date  : 03/25/2018
# Time  : O(n)
# Space : O(n)

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        pairs = {')' : '(', '}' : '{', ']' : '['}
        for bracket in s:
            if bracket in pairs:
                if not stack or stack[-1] != pairs[bracket]:
                    return False
                stack.pop()
            else:
                stack.append(bracket)
        return not stack
