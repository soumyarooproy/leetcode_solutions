# Date  : 03/25/2018
# Time  : O(n)
# Space : O(1)

class Solution:
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        carry = 0
        res = [''] * max(len(num1), len(num2))
        for i, (x, y) in enumerate(itertools.zip_longest(reversed(num1), reversed(num2), fillvalue=0)):
            s = int(x) + int(y) + carry
            res[i] = str(s % 10)
            carry = s // 10

        if carry:
            res.append('1')

        return ''.join(reversed(res))
