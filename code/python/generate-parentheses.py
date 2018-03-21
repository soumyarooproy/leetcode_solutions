# Date  : 03/20/2018
# Time  : O(c^n)
# Space : O(n)

class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        def gen_paren(s, left, right):
            if not right:
                res.append(s)
            if left:
                gen_paren(s + '(', left - 1, right)
            if right > left:
                gen_paren(s + ')', left, right - 1)
        gen_paren('', n, n)
        return res
